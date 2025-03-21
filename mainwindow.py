from PySide6.QtWidgets import QMainWindow, QLineEdit, QPushButton, QToolTip, QApplication
from PySide6.QtCore import Qt
import sys
import math
from mainwindow_ui import Ui_MainWindow

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.setWindowTitle("Calculation App")

        self.ui.lineEditWidth.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
        self.ui.lineEditWidth.textEdited.connect(self.validate_width)

        self.ui.lineEditHeight.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
        self.ui.lineEditHeight.textEdited.connect(self.validate_height)

        self.ui.lineEditU0.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
        self.ui.lineEditU0.textEdited.connect(self.validate_u0)

        self.ui.lineEditUm.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
        self.ui.lineEditUm.textEdited.connect(self.validate_um)

        self.ui.pushButton.clicked.connect(self.calculate)

    def validate_width(self, currentText):
        isInt, currentVale = self.validate_input(currentText)
        if not isInt:
            QToolTip.showText(self.ui.lineEditWidth.mapToGlobal(QPoint(0, 10)), "Invalid width!")
            self.ui.lineEditWidth.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
            return
        self.ui.lineEditWidth.setStyleSheet("QLineEdit{border:1px solid gray;border-radius:1px}")
        self.width = currentVale

    def validate_height(self, currentText):
        isInt, currentVale = self.validate_input(currentText)
        if not isInt:
            QToolTip.showText(self.ui.lineEditHeight.mapToGlobal(QPoint(0, 10)), "Invalid height!")
            self.ui.lineEditHeight.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
            return
        self.ui.lineEditHeight.setStyleSheet("QLineEdit{border:1px solid gray;border-radius:1px}")
        self.height = currentVale

    def validate_u0(self, currentText):
        isDouble, currentVale = self.validate_input(currentText, is_double=True)
        if not isDouble:
            QToolTip.showText(self.ui.lineEditU0.mapToGlobal(QPoint(0, 10)), "Invalid U0!")
            self.ui.lineEditU0.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
            return
        self.ui.lineEditU0.setStyleSheet("QLineEdit{border:1px solid gray;border-radius:1px}")
        self.u0 = currentVale

    def validate_um(self, currentText):
        isDouble, currentVale = self.validate_input(currentText, is_double=True)
        if not isDouble:
            QToolTip.showText(self.ui.lineEditUm.mapToGlobal(QPoint(0, 10)), "Invalid Um!")
            self.ui.lineEditUm.setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}")
            return
        self.ui.lineEditUm.setStyleSheet("QLineEdit{border:1px solid gray;border-radius:1px}")
        self.um = currentVale

    def validate_input(self, text, is_double=False):
        if is_double:
            try:
                value = float(text)
                return True, value
            except ValueError:
                return False, None
        else:
            try:
                value = int(text)
                return True, value
            except ValueError:
                return False, None

    def calculate(self):
        s = self.width + 400
        ow = self.width + 200
        iw = ow + 100
        b0 = int((self.width + 200) / (10 * (math.pow(1.21 * self.u0 / self.um, 2.0) - 0.417)))
        
        self.ui.lineEditS.setText(str(s))
        self.ui.lineEditOw.setText(str(ow))
        self.ui.lineEditIw.setText(str(iw))
        self.ui.lineEditB0.setText(str(b0))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())