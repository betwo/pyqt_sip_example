#!/usr/bin/python

import math
import sys
from PyQt5.QtCore import QTimer, Qt
from PyQt5.QtWidgets import QApplication, QWidget, QHBoxLayout, QVBoxLayout, QSlider, QLabel
from qt_widgets import Widget

def make_slider(label, callback):
    layout = QHBoxLayout()

    slider = QSlider(Qt.Horizontal)
    slider.setFocusPolicy(Qt.StrongFocus)
    slider.setTickPosition(QSlider.TicksBothSides)
    slider.setTickInterval(45)
    slider.setSingleStep(1)
    slider.setMinimum(0)
    slider.setMaximum(360)
    slider.valueChanged.connect(callback)

    layout.addWidget(QLabel(label))
    layout.addWidget(slider)
    return layout

if __name__ == '__main__':
    
    app = QApplication(sys.argv)

    w = QWidget()
    w.resize(250, 150)
    w.setWindowTitle('Simple')


    layout = QVBoxLayout()
    
    widget = Widget()
    layout.addWidget(widget)

    layout.addLayout(make_slider("x", lambda v: widget.setRotX(v/360.*math.pi)))
    layout.addLayout(make_slider("y", lambda v: widget.setRotY(v/360.*math.pi)))
    layout.addLayout(make_slider("z", lambda v: widget.setRotZ(v/360.*math.pi)))

    layout.addWidget(Widget())

    w.setLayout(layout)

    w.show()
    
    sys.exit(app.exec_())
