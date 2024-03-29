TEMPLATE = app
TARGET = von-neumann-emu
INCLUDEPATH += . include include/operations

!defined(APP_VERSION, var):APP_VERSION = "2.0.0-github"

info_file.input = $$PWD/info.h.in
info_file.output = $$OUT_PWD/include/info.h
QMAKE_SUBSTITUTES += info_file
OTHER_FILES += \
    info.h.in

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
HEADERS += include/AboutDialog.h \
           include/CommunicationInterface.h \
           include/CompareOperation.h \
           include/Configuration.h \
           include/ControlOperation.h \
           include/ConvertOperation.h \
           include/DialogInput.h \
           include/DialogInputBinary.h \
           include/DialogInputFloat.h \
           include/DialogInputInteger.h \
           include/FloatOperation.h \
           include/GuiInterface.h \
           include/Highlighter.h \
           include/IndexregisterOperation.h \
           include/IndirectOperation.h \
           include/InputOperation.h \
           include/IntegerOperation.h \
           include/Interpreter.h \
           include/LogicOperation.h \
           include/MainWindow.h \
           include/NegateOperation.h \
           include/NullaryOperation.h \
           include/Operation.h \
           include/Operations.h \
           include/OutputOperation.h \
           include/Parser.h \
           include/RawOperation.h \
           include/Storage.h \
           include/StorageCell.h \
           include/UnaryOperation.h \
           include/operations/ADA.h \
           include/operations/ADI.h \
           include/operations/AND.h \
           include/operations/AZJEQ.h \
           include/operations/AZJGE.h \
           include/operations/AZJGR.h \
           include/operations/AZJLE.h \
           include/operations/AZJLS.h \
           include/operations/AZJNE.h \
           include/operations/DVA.h \
           include/operations/ENA.h \
           include/operations/ENAI.h \
           include/operations/ENAR.h \
           include/operations/ENI.h \
           include/operations/ENIA.h \
           include/operations/ENTIRE.h \
           include/operations/FAD.h \
           include/operations/FDV.h \
           include/operations/FMU.h \
           include/operations/FNG.h \
           include/operations/FSB.h \
           include/operations/HLT.h \
           include/operations/INB.h \
           include/operations/INI.h \
           include/operations/INR.h \
           include/operations/IRE.h \
           include/operations/LDA.h \
           include/operations/MDA.h \
           include/operations/MUA.h \
           include/operations/NGA.h \
           include/operations/NOP.h \
           include/operations/NOT.h \
           include/operations/OR.h \
           include/operations/OUB.h \
           include/operations/OUI.h \
           include/operations/OUR.h \
           include/operations/PRIM.h \
           include/operations/RIN.h \
           include/operations/SBA.h \
           include/operations/SBI.h \
           include/operations/SRJ.h \
           include/operations/SRR.h \
           include/operations/STA.h \
           include/operations/STP.h \
           include/operations/UJP.h \
           include/operations/XOR.h
FORMS += ui/AboutDialog.ui ui/DialogInput.ui ui/MainWindow.ui
SOURCES += src/AboutDialog.cpp \
           src/CommunicationInterface.cpp \
           src/CompareOperation.cpp \
           src/Configuration.cpp \
           src/ControlOperation.cpp \
           src/ConvertOperation.cpp \
           src/DialogInput.cpp \
           src/DialogInputBinary.cpp \
           src/DialogInputFloat.cpp \
           src/DialogInputInteger.cpp \
           src/emulator.cpp \
           src/FloatOperation.cpp \
           src/GuiInterface.cpp \
           src/Highlighter.cpp \
           src/IndexregisterOperation.cpp \
           src/IndirectOperation.cpp \
           src/InputOperation.cpp \
           src/IntegerOperation.cpp \
           src/Interpreter.cpp \
           src/LogicOperation.cpp \
           src/MainWindow.cpp \
           src/NegateOperation.cpp \
           src/NullaryOperation.cpp \
           src/Operation.cpp \
           src/OutputOperation.cpp \
           src/Parser.cpp \
           src/StorageCell.cpp \
           src/UnaryOperation.cpp \
           src/operations/ADA.cpp \
           src/operations/ADI.cpp \
           src/operations/AND.cpp \
           src/operations/AZJEQ.cpp \
           src/operations/AZJGE.cpp \
           src/operations/AZJGR.cpp \
           src/operations/AZJLE.cpp \
           src/operations/AZJLS.cpp \
           src/operations/AZJNE.cpp \
           src/operations/DVA.cpp \
           src/operations/ENA.cpp \
           src/operations/ENAI.cpp \
           src/operations/ENAR.cpp \
           src/operations/ENI.cpp \
           src/operations/ENIA.cpp \
           src/operations/ENTIRE.cpp \
           src/operations/FAD.cpp \
           src/operations/FDV.cpp \
           src/operations/FMU.cpp \
           src/operations/FNG.cpp \
           src/operations/FSB.cpp \
           src/operations/HLT.cpp \
           src/operations/INB.cpp \
           src/operations/INI.cpp \
           src/operations/INR.cpp \
           src/operations/IRE.cpp \
           src/operations/LDA.cpp \
           src/operations/MDA.cpp \
           src/operations/MUA.cpp \
           src/operations/NGA.cpp \
           src/operations/NOP.cpp \
           src/operations/NOT.cpp \
           src/operations/OR.cpp \
           src/operations/OUB.cpp \
           src/operations/OUI.cpp \
           src/operations/OUR.cpp \
           src/operations/PRIM.cpp \
           src/operations/RIN.cpp \
           src/operations/SBA.cpp \
           src/operations/SBI.cpp \
           src/operations/SRJ.cpp \
           src/operations/SRR.cpp \
           src/operations/STA.cpp \
           src/operations/STP.cpp \
           src/operations/UJP.cpp \
           src/operations/XOR.cpp
RESOURCES += res/icons.qrc
