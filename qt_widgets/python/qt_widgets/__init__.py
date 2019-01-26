import libqt_widgets_sip
import sys

print(libqt_widgets_sip.__dict__)
sys.modules['qt_widgets'] = libqt_widgets_sip