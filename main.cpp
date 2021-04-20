#include <QApplication>
#include <QMessageBox>
#include <QSysInfo>
#include <QScreen>


QString english{
    "The quick brown fox jumps over the lazy dog."
};
QString chinese{
    "我能吞下玻璃而不伤身体。"
};
QString japanese{
    "いろはにほへと / ちりぬるを / わかよたれそ / つねならむ / うゐのおくやま / けふこえて / あさきゆめみし / ゑひもせす"
};
QString korean{
    "키스의 고유조건은 입술끼리 만나야 하고 특별한 기술은 필요치 않다."
};

QString sentences = QString{"%1\n%2\n%3\n%4"}.arg(english, chinese, japanese, korean);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGuiApplication::setApplicationDisplayName(
                QString{"DPI %1 on %2"}
                .arg(
                    QString::number(QGuiApplication::primaryScreen()->logicalDotsPerInch()),
                    QSysInfo::prettyProductName()));

    QFont f = QApplication::font();

    // https://stackoverflow.com/questions/32589776/qmessagebox-you-can-select-text-from
    QMessageBox mb;
    mb.setTextInteractionFlags(
                Qt::TextInteractionFlag::TextSelectableByKeyboard | Qt::TextInteractionFlag::TextSelectableByMouse);


    mb.setText(
                QString{"%1\n\nfamily: %2\npointSize: %3\npixelSize: %4"}
                .arg(sentences, f.family())
                .arg(f.pointSize())
                .arg(f.pixelSize()));
    mb.exec();


    f.setPointSize(18);
    // 18 pt == 18/72 in
    //   96 DPI: 24 px
    //   72 DPI: 18 px
    QApplication::setFont(f);


    mb.setText(
                QString{"%1\n\nfamily: %2\npointSize: %3\npixelSize: %4"}
                .arg(sentences, f.family())
                .arg(f.pointSize())
                .arg(f.pixelSize()));
    mb.exec();


    f.setPixelSize(32);
    // 96 DPI: 32 px == 24 pt
    // 72 DPI: 32 px == 32 pt
    QApplication::setFont(f);


    mb.setText(
                QString{"%1\n\nfamily: %2\npointSize: %3\npixelSize: %4"}
                .arg(sentences, f.family())
                .arg(f.pointSize())
                .arg(f.pixelSize()));
    mb.exec();


    return 0;
}
