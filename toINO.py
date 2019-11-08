import cv2, os, sys, re
import numpy as np
from PIL import Image, GifImagePlugin
from math import *
from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Window(object):
    def setupUi(self, Window):
        Window.setObjectName("Window")
        Window.resize(316, 256)
        self.centralwidget = QtWidgets.QWidget(Window)
        self.centralwidget.setObjectName("centralwidget")
        self.Tabs = QtWidgets.QTabWidget(self.centralwidget)
        self.Tabs.setGeometry(QtCore.QRect(0, 0, 321, 241))
        self.Tabs.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.Tabs.setObjectName("Tabs")
        self.PNG = QtWidgets.QWidget()
        self.PNG.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.PNG.setObjectName("PNG")
        self.pushButton = QtWidgets.QPushButton(self.PNG)
        self.pushButton.setGeometry(QtCore.QRect(120, 180, 75, 23))
        self.pushButton.setObjectName("pushButton")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.PNG)
        self.lineEdit_2.setGeometry(QtCore.QRect(110, 80, 171, 31))
        self.lineEdit_2.setText("")
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.label_2 = QtWidgets.QLabel(self.PNG)
        self.label_2.setGeometry(QtCore.QRect(10, 80, 101, 31))
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.lineEdit = QtWidgets.QLineEdit(self.PNG)
        self.lineEdit.setGeometry(QtCore.QRect(110, 130, 171, 31))
        self.lineEdit.setObjectName("lineEdit")
        self.label = QtWidgets.QLabel(self.PNG)
        self.label.setGeometry(QtCore.QRect(20, 130, 91, 31))
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.label_3 = QtWidgets.QLabel(self.PNG)
        self.label_3.setGeometry(QtCore.QRect(20, 30, 101, 31))
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.PNG)
        self.lineEdit_3.setGeometry(QtCore.QRect(110, 30, 121, 31))
        self.lineEdit_3.setText("")
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.pushButton_3 = QtWidgets.QPushButton(self.PNG)
        self.pushButton_3.setGeometry(QtCore.QRect(240, 30, 51, 31))
        self.pushButton_3.setObjectName("pushButton_3")
        self.Tabs.addTab(self.PNG, "")
        self.GIF = QtWidgets.QWidget()
        self.GIF.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.GIF.setObjectName("GIF")
        self.lineEdit_4 = QtWidgets.QLineEdit(self.GIF)
        self.lineEdit_4.setGeometry(QtCore.QRect(110, 110, 171, 31))
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.label_4 = QtWidgets.QLabel(self.GIF)
        self.label_4.setGeometry(QtCore.QRect(20, 110, 91, 31))
        self.label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.label_4.setObjectName("label_4")
        self.label_8 = QtWidgets.QLabel(self.GIF)
        self.label_8.setGeometry(QtCore.QRect(20, 50, 101, 31))
        self.label_8.setAlignment(QtCore.Qt.AlignCenter)
        self.label_8.setObjectName("label_8")
        self.pushButton_4 = QtWidgets.QPushButton(self.GIF)
        self.pushButton_4.setGeometry(QtCore.QRect(120, 180, 75, 23))
        self.pushButton_4.setObjectName("pushButton_4")
        self.lineEdit_8 = QtWidgets.QLineEdit(self.GIF)
        self.lineEdit_8.setGeometry(QtCore.QRect(110, 50, 121, 31))
        self.lineEdit_8.setText("")
        self.lineEdit_8.setObjectName("lineEdit_8")
        self.pushButton_5 = QtWidgets.QPushButton(self.GIF)
        self.pushButton_5.setGeometry(QtCore.QRect(240, 50, 51, 31))
        self.pushButton_5.setObjectName("pushButton_5")
        self.Tabs.addTab(self.GIF, "")
        self.MP4 = QtWidgets.QWidget()
        self.MP4.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.MP4.setObjectName("MP4")
        self.lineEdit_5 = QtWidgets.QLineEdit(self.MP4)
        self.lineEdit_5.setGeometry(QtCore.QRect(110, 100, 171, 31))
        self.lineEdit_5.setText("")
        self.lineEdit_5.setObjectName("lineEdit_5")
        self.label_5 = QtWidgets.QLabel(self.MP4)
        self.label_5.setGeometry(QtCore.QRect(0, 100, 111, 31))
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.lineEdit_6 = QtWidgets.QLineEdit(self.MP4)
        self.lineEdit_6.setGeometry(QtCore.QRect(110, 140, 171, 31))
        self.lineEdit_6.setObjectName("lineEdit_6")
        self.label_6 = QtWidgets.QLabel(self.MP4)
        self.label_6.setGeometry(QtCore.QRect(20, 140, 91, 31))
        self.label_6.setAlignment(QtCore.Qt.AlignCenter)
        self.label_6.setObjectName("label_6")
        self.lineEdit_7 = QtWidgets.QLineEdit(self.MP4)
        self.lineEdit_7.setGeometry(QtCore.QRect(110, 60, 171, 31))
        self.lineEdit_7.setText("")
        self.lineEdit_7.setObjectName("lineEdit_7")
        self.label_7 = QtWidgets.QLabel(self.MP4)
        self.label_7.setGeometry(QtCore.QRect(10, 60, 101, 31))
        self.label_7.setAlignment(QtCore.Qt.AlignCenter)
        self.label_7.setObjectName("label_7")
        self.label_9 = QtWidgets.QLabel(self.MP4)
        self.label_9.setGeometry(QtCore.QRect(20, 20, 101, 31))
        self.label_9.setAlignment(QtCore.Qt.AlignCenter)
        self.label_9.setObjectName("label_9")
        self.pushButton_2 = QtWidgets.QPushButton(self.MP4)
        self.pushButton_2.setGeometry(QtCore.QRect(120, 180, 75, 23))
        self.pushButton_2.setObjectName("pushButton_2")
        self.lineEdit_9 = QtWidgets.QLineEdit(self.MP4)
        self.lineEdit_9.setGeometry(QtCore.QRect(110, 20, 121, 31))
        self.lineEdit_9.setText("")
        self.lineEdit_9.setObjectName("lineEdit_9")
        self.pushButton_6 = QtWidgets.QPushButton(self.MP4)
        self.pushButton_6.setGeometry(QtCore.QRect(240, 20, 51, 31))
        self.pushButton_6.setObjectName("pushButton_6")
        self.Tabs.addTab(self.MP4, "")

        self.retranslateUi(Window)
        self.Tabs.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(Window)

    def retranslateUi(self, Window):
        _translate = QtCore.QCoreApplication.translate
        Window.setWindowTitle(_translate("Window", "ConvertToINO"))
        self.pushButton.setText(_translate("Window", "Ok"))
        self.label_2.setText(_translate("Window", "Number of tiles"))
        self.label.setText(_translate("Window", "Resolution_X"))
        self.label_3.setText(_translate("Window", "Browse File"))
        self.pushButton_3.setText(_translate("Window", "Browse"))
        self.Tabs.setTabText(self.Tabs.indexOf(self.PNG), _translate("Window", "PNG"))
        self.label_4.setText(_translate("Window", "Resolution_X"))
        self.label_8.setText(_translate("Window", "Browse File"))
        self.pushButton_4.setText(_translate("Window", "Ok"))
        self.pushButton_5.setText(_translate("Window", "Browse"))
        self.Tabs.setTabText(self.Tabs.indexOf(self.GIF), _translate("Window", "GIF"))
        self.label_5.setText(_translate("Window", "Number of frames"))
        self.label_6.setText(_translate("Window", "Resolution_X"))
        self.label_7.setText(_translate("Window", "Save directory"))
        self.label_9.setText(_translate("Window", "Browse File"))
        self.pushButton_2.setText(_translate("Window", "Ok"))
        self.pushButton_6.setText(_translate("Window", "Browse"))
        self.Tabs.setTabText(self.Tabs.indexOf(self.MP4), _translate("Window", "MP4"))

def crop(ImgArr):
    i = 0
    while sum(sum(ImgArr[i])) == 0:
        ImgArr = np.delete(ImgArr, i, 0)
    i = -1
    while sum(sum(ImgArr[i])) == 0:
        ImgArr = np.delete(ImgArr, i, 0)
    i = 0
    while sum(sum(ImgArr[:,i])) == 0:
        ImgArr = np.delete(ImgArr, i, 1)
    i = -1
    while sum(sum(ImgArr[:,i])) == 0:
        ImgArr = np.delete(ImgArr, i, 1)
    return ImgArr

ALPHA = "ALPHA"
alpha_bit = 0xFE

def replace_alpha(col, frame):
    frame = frame.copy();
    for i in range(frame.shape[0]):
        for j in range(frame.shape[1]):
            if sum([1 for X,Y in zip(frame[i][j], col) if X != Y]) == 0:
                for k in range(4): frame[i][j][k] = 0
    return frame

def RGBA_to_bitmap(col):
    #8 BIT: BBBGGGRR
    if len(col) == 4:
        if col[3] == 0: return ALPHA
    col = np.array(col)/255.
    bitcol = int(round(col[0]*3) + round(col[1]*7)*4 + round(col[2]*7)*4*8)
    if bitcol == alpha_bit: bitcol += 1
    return bitcol

def bitmap_to_RGBA(bitcol):
    #8 BIT: BBBGGGRR
    if bitcol == ALPHA: return [0,0,0,0]
    R = bitcol%4
    G = bitcol//4 % 8
    B = bitcol//(4*8)
    return [int(x) for x in [R/3.*255, G/7.*255, B/7.*255, 255]]
    
def GetBitmap(ImgArr):
    shape = ImgArr.shape
    Bitmap = [[RGBA_to_bitmap(COL) for COL in row] for row in ImgArr]
    return {"X": shape[1], "Y": shape[0]}, Bitmap

def Bitmap_to_string(Bitmap):
    return ", ".join([str(item) for sublist in Bitmap for item in sublist])

def Bitmap_to_image(Bitmap):
    return Image.fromarray(np.array([[bitmap_to_RGBA(COL) for COL in row] for row in Bitmap], dtype="uint8"))

def Filename_to_bitmap(FILENAME, tile, RESOLUTION_x, Orientation = "xy"):
    '''
    FILENAME must be of an image with an alpha channel
    RESOLUTION_x is an estimate of the x-resolution of the final bitmap
    
    returns:
        STRING, string of final bitmap. Just copy and paste it
        shape: shape of final bitmap (after cropping extra alpha rows and columns)
    '''
    
    im = np.asarray(Image.open(FILENAME))
    output = []
    RX = im.shape[0]
    RY = im.shape[1]//tile
    scale = RESOLUTION_x/RX
    RESOLUTION = (round(RX*scale), round(RY*scale))
    tiles = [im[x:x+RX,y:y+RY] for x in range(0,im.shape[0],RX) for y in range(0,im.shape[1],RY)]
    for elem in tiles:
        ImgArr = np.asarray(Image.fromarray(elem).resize(RESOLUTION, Image.NEAREST))
        ImgArrCrop = crop(ImgArr)
        shape, Bitmap = GetBitmap(ImgArrCrop)
        output.append((Bitmap_to_string(Bitmap), shape, Bitmap_to_image(Bitmap)))
    return output


def main(CHOICE="", FILENAME="", RES=64, TILES=1, FRAMES=10, SAVE=""):
    OUTPUT = []
    #print(CHOICE, FILENAME, RES, TILES, FRAMES, SAVE)
    filename = "Bitmap/Bitmap.ino"
    try:
        os.makedirs(os.path.dirname(filename), True)
    except:
        print("Conflict!")
    with open(r"Bitmap/Bitmap.ino", "w") as f:
        f.write("#include <Wire.h>\n#include <SPI.h>\n#include <TinyScreen.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <math.h>\nTinyScreen display = TinyScreen(0);\n#define ALPHA 0xFE\n#define BACKGROUND 0x00\n\n")
    if (CHOICE == "1"):
        OUTPUT = Filename_to_bitmap(FILENAME, TILES, RES, Orientation = "yx")
    elif (CHOICE == "2"):
        GIF = Image.open(FILENAME)
        n_frames = GIF.n_frames
        FRAMES = []
        for i in range(n_frames):
            GIF.seek(i)
            img = GIF.copy()
            FRAMES.append(img)
            
        scale = float(RES)/np.asarray(FRAMES[0]).shape[1]
        FRAMES_resized = [Img.resize((int(np.asarray(Img).shape[1] * scale), int(np.asarray(Img).shape[0] * scale)), Image.NEAREST) for Img in FRAMES]
        FRAMES_RGBA = [np.asarray(Img.convert("RGBA")) for Img in FRAMES_resized]
        FRAMES_RGBA = [replace_alpha([255, 255, 255,   0], frame) for frame in FRAMES_RGBA]
        FRAMES_cropped = [crop(Img) for Img in FRAMES_RGBA]
        Bitmap = [GetBitmap(Img) for Img in FRAMES_cropped]
        OUTPUT = [(Bitmap_to_string(bitmap), shape) for shape, bitmap in Bitmap]
    elif (CHOICE == "3"):
        cam = cv2.VideoCapture(FILENAME)
        try:
            if not os.path.exists(SAVE): 
                os.makedirs(SAVE)
        except OSError: 
            print ('Error: Creating directory of '+SAVE)
        currentframe = 0
        while(True):
            ret,frame = cam.read()
            if ret:
                name = SAVE+'/frame' + str(currentframe) + '.png'
                cv2.imwrite(name, frame)
                currentframe += 1
            else: 
                break
        cam.release() 
        cv2.destroyAllWindows()
        for num in range(FRAMES):
            OUTPUT.append(Filename_to_bitmap(SAVE+"/frame"+str(num*floor(currentframe/FRAMES))+".png", 1, RES, Orientation = "yx")[0])
    else: return
    with open(r"Bitmap/Bitmap.ino", "a") as f:
        f.write("const unsigned char SPRITE_XY["+str(2*len(OUTPUT))+"] PROGMEM = {"+str([(elem[1]['X'], elem[1]['Y']) for elem in OUTPUT]).replace('(', '').replace(')', '')[1:-1]+"};\n")
        for num in range(len(OUTPUT)):
            f.write("const unsigned char SPRITE_"+str(num)+"["+str(OUTPUT[num][1]['X']*OUTPUT[num][1]['Y'])+"] PROGMEM = {"+OUTPUT[num][0]+"};\n")
        f.write("const unsigned char * const SPRITE_ARR["+str(len(OUTPUT))+"] PROGMEM = {"+str(["SPRITE_"+str(num) for num in range(len(OUTPUT))]).replace("'", "")[1:-1]+"};\n")
        f.write("\nconst unsigned char Rx = 96;\nconst unsigned char Ry = 64;\nunsigned char LINEBUFFER[Rx];\nvoid setup() {\n\tWire.begin();\n\tdisplay.begin();\n\tdisplay.setBrightness(15);\n}\nvoid loop() {\n\tunsigned char frame;\n\tfor (frame = 0; frame < "+str(len(OUTPUT))+"; frame++){\n\t\tDrawScreen(frame);\n\t\tdelay(50);\n\t}\n}\nvoid DrawScreen(unsigned char frame){\n\tunsigned char SPRITE_FRAME;\n\tSPRITE_FRAME = frame%"+str(len(OUTPUT))+";\n\tunsigned char SPRITE_X, SPRITE_Y;\n\tSPRITE_X = pgm_read_byte_near(SPRITE_XY + (SPRITE_FRAME)*2);\n\tSPRITE_Y = pgm_read_byte_near(SPRITE_XY + (SPRITE_FRAME)*2 + 1);\n\tdisplay.setX(0, Rx-1);\n\tdisplay.setY(0, Ry-1);\n\tdisplay.startData();\n\tunsigned char LINE_N, var;\n\tfor (LINE_N = 0; LINE_N < Ry; LINE_N++){\n\t\tfor (var = 0; var < Rx; var++) LINEBUFFER[var] = BACKGROUND;\n\t\tDrawSprite((PGM_P)pgm_read_word(&(SPRITE_ARR[SPRITE_FRAME])), SPRITE_X, SPRITE_Y, Rx/2 - SPRITE_X/2, Ry/2 - SPRITE_Y/2, LINE_N);\n\t\tdisplay.writeBuffer(LINEBUFFER, Rx);\n\t}\n\tdisplay.endTransfer();\n}\nvoid DrawSprite(long SpritePointer, unsigned char SpriteSize_X,  unsigned char SpriteSize_Y, unsigned char x, unsigned char y, unsigned char line_n){\n\tif (line_n < y || line_n >= y + SpriteSize_Y){return;}\n\tunsigned char pos, pixel;\n\tfor (pos = x; pos < x + SpriteSize_X; pos++){\n\t\tpixel = pgm_read_byte_near(SpritePointer + SpriteSize_X*(line_n - y) + pos - x);\n\t\tif (pixel != ALPHA) LINEBUFFER[pos] = pixel;\n\t}\n}")

class Gui(QtWidgets.QDialog, Ui_Window):
    def __init__(self):
        QtWidgets.QDialog.__init__(self)
        self.ui = Ui_Window()
        self.ui.setupUi(self)
        self.ui.pushButton.clicked.connect(self.run_png)
        self.ui.pushButton_4.clicked.connect(self.run_gif)
        self.ui.pushButton_2.clicked.connect(self.run_mp4)
        self.ui.pushButton_3.clicked.connect(self.browse_png)
        self.ui.pushButton_5.clicked.connect(self.browse_gif)
        self.ui.pushButton_6.clicked.connect(self.browse_mp4)
    
    def run_png(self):
        res_png = self.ui.lineEdit.displayText()
        tile_png = self.ui.lineEdit_2.displayText()
        file_png = self.ui.lineEdit_3.displayText()
        if not res_png or not tile_png or not file_png:
            return
        else:
            main(CHOICE="1", RES=int(res_png), TILES=int(tile_png), FILENAME=file_png)
            self.close()
    
    def run_gif(self):
        res_gif = self.ui.lineEdit_4.displayText()
        file_gif = self.ui.lineEdit_8.displayText()
        if not res_gif or not file_gif:
            return
        else:
            main(CHOICE="2", RES=int(res_gif), FILENAME=file_gif)
            self.close()
    
    def run_mp4(self):
        frames_mp4 = self.ui.lineEdit_5.displayText()
        res_mp4 = self.ui.lineEdit_6.displayText()
        save_mp4 = self.ui.lineEdit_7.displayText()
        file_mp4 = self.ui.lineEdit_9.displayText()
        if not frames_mp4 or not res_mp4 or not save_mp4 or not file_mp4:
            return
        else:
            main(CHOICE="3", FRAMES=int(frames_mp4), RES=int(res_mp4), SAVE=save_mp4, FILENAME=file_mp4)
            self.close()
    
    def browse_png(self):
        options = QtWidgets.QFileDialog.Options()
        options |= QtWidgets.QFileDialog.DontUseNativeDialog
        fileName, _ = QtWidgets.QFileDialog.getOpenFileName(None,"Browse PNG File","","All Files (*);;PNG (*.png)",options=options)
        if fileName:
            if not re.match("^.*[.]png$", fileName):
                self.ui.lineEdit_3.setText("")
            else:
                self.ui.lineEdit_3.setText(fileName)
    
    def browse_gif(self):
        options = QtWidgets.QFileDialog.Options()
        options |= QtWidgets.QFileDialog.DontUseNativeDialog
        fileName, _ = QtWidgets.QFileDialog.getOpenFileName(None,"Browse GIF File","","All Files (*);;GIF (*.gif)",options=options)
        if fileName:
            if not re.match("^.*[.]gif$", fileName):
                self.ui.lineEdit_8.setText("")
            else:
                self.ui.lineEdit_8.setText(fileName)
    
    def browse_mp4(self):
        options = QtWidgets.QFileDialog.Options()
        options |= QtWidgets.QFileDialog.DontUseNativeDialog
        fileName, _ = QtWidgets.QFileDialog.getOpenFileName(None,"Browse MP4 File","","All Files (*);;MP4 (*.mp4)",options=options)
        if fileName:
            if not re.match("^.*[.]mp4$", fileName):
                self.ui.lineEdit_9.setText("")
            else:
                self.ui.lineEdit_9.setText(fileName)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = Gui()
    window.show()
    sys.exit(app.exec())