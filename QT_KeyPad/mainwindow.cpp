#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

static bool CapsLockActive = false;

static void setButtonEnable(QPushButton* btn)
{
    QPalette plt_enable = QPalette(Qt::GlobalColor::lightGray);
    btn->setPalette(plt_enable);
}

static void setButtonDisable(QPushButton* btn)
{
    QPalette plt_disable = QPalette(Qt::GlobalColor::color0);
    btn->setPalette(plt_disable);
}

static void disableAllButtons(Ui_MainWindow* ui)
{
    setButtonDisable(ui->pushButton_Q);
    setButtonDisable(ui->pushButton_W);
    setButtonDisable(ui->pushButton_E);
    setButtonDisable(ui->pushButton_R);
    setButtonDisable(ui->pushButton_T);
    setButtonDisable(ui->pushButton_Y);
    setButtonDisable(ui->pushButton_U);
    setButtonDisable(ui->pushButton_I);
    setButtonDisable(ui->pushButton_O);
    setButtonDisable(ui->pushButton_P);
    setButtonDisable(ui->pushButton_G1);
    setButtonDisable(ui->pushButton_U1);
    setButtonDisable(ui->pushButton_A);
    setButtonDisable(ui->pushButton_S);
    setButtonDisable(ui->pushButton_D);
    setButtonDisable(ui->pushButton_F);
    setButtonDisable(ui->pushButton_G);
    setButtonDisable(ui->pushButton_H);
    setButtonDisable(ui->pushButton_J);
    setButtonDisable(ui->pushButton_K);
    setButtonDisable(ui->pushButton_L);
    setButtonDisable(ui->pushButton_S1);
    setButtonDisable(ui->pushButton_I1);
    setButtonDisable(ui->pushButton_Z);
    setButtonDisable(ui->pushButton_X);
    setButtonDisable(ui->pushButton_C);
    setButtonDisable(ui->pushButton_V);
    setButtonDisable(ui->pushButton_B);
    setButtonDisable(ui->pushButton_N);
    setButtonDisable(ui->pushButton_M);
    setButtonDisable(ui->pushButton_O1);
    setButtonDisable(ui->pushButton_C1);
    setButtonDisable(ui->pushButton_Ex);
    setButtonDisable(ui->pushButton_Quote);
    setButtonDisable(ui->pushButton_XOR);
    setButtonDisable(ui->pushButton_Hash);
    setButtonDisable(ui->pushButton_Add);
    setButtonDisable(ui->pushButton_Dolar);
    setButtonDisable(ui->pushButton_Mod);
    setButtonDisable(ui->pushButton_Addr);
    setButtonDisable(ui->pushButton_Slash);
    setButtonDisable(ui->pushButton_LCurly);
    setButtonDisable(ui->pushButton_LParanthesis);
    setButtonDisable(ui->pushButton_LIndex);
    setButtonDisable(ui->pushButton_RParanthesis);
    setButtonDisable(ui->pushButton_RIndex);
    setButtonDisable(ui->pushButton_Equal);
    setButtonDisable(ui->pushButton_RCurly);
    setButtonDisable(ui->pushButton_Question);
    setButtonDisable(ui->pushButton_Asterix);
    setButtonDisable(ui->pushButton_BackSlash);
    setButtonDisable(ui->pushButton_2Quote);
    setButtonDisable(ui->pushButton_Underscore);
    setButtonDisable(ui->pushButton_Hyphen);
    setButtonDisable(ui->pushButton_Tilda);
    setButtonDisable(ui->pushButton_SColon);
    setButtonDisable(ui->pushButton_Comma);
    setButtonDisable(ui->pushButton_Colon);
    setButtonDisable(ui->pushButton_Dot);
    setButtonDisable(ui->pushButton_RS);
    setButtonDisable(ui->pushButton_LS);
    setButtonDisable(ui->pushButton_OR);
    setButtonDisable(ui->pushButton_ENT);
    setButtonDisable(ui->pushButton_DEL);
    setButtonDisable(ui->pushButton_SP);
    setButtonDisable(ui->pushButton_Caps);
    setButtonDisable(ui->pushButton_Close);
    setButtonDisable(ui->pushButton_0);
    setButtonDisable(ui->pushButton_1);
    setButtonDisable(ui->pushButton_2);
    setButtonDisable(ui->pushButton_3);
    setButtonDisable(ui->pushButton_4);
    setButtonDisable(ui->pushButton_5);
    setButtonDisable(ui->pushButton_6);
    setButtonDisable(ui->pushButton_7);
    setButtonDisable(ui->pushButton_8);
    setButtonDisable(ui->pushButton_9);
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    disableAllButtons(ui);

    //Take screen info
    /*
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    this->resize(width, height);
    qDebug() << "height= " << height << ", width= " << width;
    qDebug() << "Layout2Windowwidth= " << ui->horizontalLayout_1->geometry().size();*/


    QObject::connect(ui->pushButton_Close, &QAbstractButton::pressed, this, &QWidget::close);

    //Make MainWindow transparent
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_NoSystemBackground, true);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    //Disable Text Edit
    ui->monitor->setAttribute(Qt::WA_WState_Hidden, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
    case Qt::Key_Q:
        setButtonEnable(ui->pushButton_Q);
        break;
    case Qt::Key_W:
        setButtonEnable(ui->pushButton_W);
        break;
    case Qt::Key_E:
        setButtonEnable(ui->pushButton_E);
        break;
    case Qt::Key_R:
        setButtonEnable(ui->pushButton_R);
        break;
    case Qt::Key_T:
        setButtonEnable(ui->pushButton_T);
        break;
    case Qt::Key_Y:
        setButtonEnable(ui->pushButton_Y);
        break;
    case Qt::Key_U:
        setButtonEnable(ui->pushButton_U);
        break;
    case Qt::Key_I:
        setButtonEnable(ui->pushButton_I);
        break;
    case Qt::Key_O:
        setButtonEnable(ui->pushButton_O);
        break;
    case Qt::Key_P:
        setButtonEnable(ui->pushButton_P);
        break;
    case Qt::Key_G1:
        setButtonEnable(ui->pushButton_G1);
        break;
    case Qt::Key_Udiaeresis:
        setButtonEnable(ui->pushButton_U1);
        break;
    case Qt::Key_A:
        setButtonEnable(ui->pushButton_A);
        break;
    case Qt::Key_S:
        setButtonEnable(ui->pushButton_S);
        break;
    case Qt::Key_D:
        setButtonEnable(ui->pushButton_D);
        break;
    case Qt::Key_F:
        setButtonEnable(ui->pushButton_F);
        break;
    case Qt::Key_G:
        setButtonEnable(ui->pushButton_G);
        break;
    case Qt::Key_H:
        setButtonEnable(ui->pushButton_H);
        break;
    case Qt::Key_J:
        setButtonEnable(ui->pushButton_J);
        break;
    case Qt::Key_K:
        setButtonEnable(ui->pushButton_K);
        break;
    case Qt::Key_L:
        setButtonEnable(ui->pushButton_L);
        break;
    case Qt::Key_S1:
        setButtonEnable(ui->pushButton_S1);
        break;
    case Qt::Key_Z:
        setButtonEnable(ui->pushButton_Z);
        break;
    case Qt::Key_X:
        setButtonEnable(ui->pushButton_X);
        break;
    case Qt::Key_C:
        setButtonEnable(ui->pushButton_C);
        break;
    case Qt::Key_V:
        setButtonEnable(ui->pushButton_V);
        break;
    case Qt::Key_B:
        setButtonEnable(ui->pushButton_B);
        break;
    case Qt::Key_N:
        setButtonEnable(ui->pushButton_N);
        break;
    case Qt::Key_M:
        setButtonEnable(ui->pushButton_M);
        break;
    case Qt::Key_Odiaeresis:
        setButtonEnable(ui->pushButton_O1);
        break;
    case Qt::Key_Ccedilla:
        setButtonEnable(ui->pushButton_C1);
        break;
    case Qt::Key_Exclam:
        setButtonEnable(ui->pushButton_Ex);
        break;
    case Qt::Key_Apostrophe:
        setButtonEnable(ui->pushButton_Quote);
        break;
    case Qt::Key_Hat:
        setButtonEnable(ui->pushButton_XOR);
        break;
    case Qt::Key_AsciiCircum:
        setButtonEnable(ui->pushButton_Hash);
        break;
    case Qt::Key_Plus:
        setButtonEnable(ui->pushButton_Add);
        break;
    case Qt::Key_Dollar:
        setButtonEnable(ui->pushButton_Dolar);
        break;
    case Qt::Key_Percent:
        setButtonEnable(ui->pushButton_Mod);
        break;
    case Qt::Key_Ampersand:
        setButtonEnable(ui->pushButton_Addr);
        break;
    case Qt::Key_Slash:
        setButtonEnable(ui->pushButton_Slash);
        break;
    case Qt::Key_BraceLeft:
        setButtonEnable(ui->pushButton_LCurly);
        break;
    case Qt::Key_ParenLeft:
        setButtonEnable(ui->pushButton_LParanthesis);
        break;
    case Qt::Key_BracketLeft:
        setButtonEnable(ui->pushButton_LIndex);
        break;
    case Qt::Key_ParenRight:
        setButtonEnable(ui->pushButton_RParanthesis);
        break;
    case Qt::Key_BracketRight:
        setButtonEnable(ui->pushButton_RIndex);
        break;
    case Qt::Key_Equal:
        setButtonEnable(ui->pushButton_Equal);
        break;
    case Qt::Key_BraceRight:
        setButtonEnable(ui->pushButton_RCurly);
        break;
    case Qt::Key_Question:
        setButtonEnable(ui->pushButton_Question);
        break;
    case Qt::Key_Asterisk:
        setButtonEnable(ui->pushButton_Asterix);
        break;
    case Qt::Key_Backslash:
        setButtonEnable(ui->pushButton_BackSlash);
        break;
    case Qt::Key_QuoteDbl:
        setButtonEnable(ui->pushButton_2Quote);
        break;
    case Qt::Key_Underscore:
        setButtonEnable(ui->pushButton_Underscore);
        break;
    case Qt::Key_Minus:
        setButtonEnable(ui->pushButton_Hyphen);
        break;
    case Qt::Key_AsciiTilde:
        setButtonEnable(ui->pushButton_Tilda);
        break;
    case Qt::Key_Semicolon:
        setButtonEnable(ui->pushButton_SColon);
        break;
    case Qt::Key_Comma:
        setButtonEnable(ui->pushButton_Comma);
        break;
    case Qt::Key_Colon:
        setButtonEnable(ui->pushButton_Colon);
        break;
    case Qt::Key_Period:
        setButtonEnable(ui->pushButton_Dot);
        break;
    case Qt::Key_Greater:
        setButtonEnable(ui->pushButton_RS);
        break;
    case Qt::Key_Bar:
        setButtonEnable(ui->pushButton_OR);
        break;
    case Qt::Key_Less:
        setButtonEnable(ui->pushButton_LS);
        break;
    case Qt::Key_Enter:
        setButtonEnable(ui->pushButton_ENT);
        break;
    case Qt::Key_Return:
        setButtonEnable(ui->pushButton_ENT);
        break;
    case Qt::Key_Delete:
        setButtonEnable(ui->pushButton_DEL);
        break;
    case Qt::Key_Space:
        setButtonEnable(ui->pushButton_SP);
        break;
    case Qt::Key_CapsLock:
        if(ui->pushButton_Caps->palette().color(QPalette::Active,QPalette::Button) == Qt::GlobalColor::lightGray)
        {
            setButtonDisable(ui->pushButton_Caps);;
            CapsLockActive = false;
        }
        else
        {
           setButtonEnable(ui->pushButton_Caps);;
            CapsLockActive = true;
        }
        break;
    case Qt::Key_0:
        setButtonEnable(ui->pushButton_0);
        break;
    case Qt::Key_1:
        setButtonEnable(ui->pushButton_1);
        break;
    case Qt::Key_2:
        setButtonEnable(ui->pushButton_2);
        break;
    case Qt::Key_3:
        setButtonEnable(ui->pushButton_3);
        break;
    case Qt::Key_4:
        setButtonEnable(ui->pushButton_4);
        break;
    case Qt::Key_5:
        setButtonEnable(ui->pushButton_5);
        break;
    case Qt::Key_6:
        setButtonEnable(ui->pushButton_6);
        break;
    case Qt::Key_7:
        setButtonEnable(ui->pushButton_7);
        break;
    case Qt::Key_8:
        setButtonEnable(ui->pushButton_8);
        break;
    case Qt::Key_9:
        setButtonEnable(ui->pushButton_9);
        break;
    default:
        break;
    }


    ui->monitor->moveCursor(QTextCursor::End);
    ui->monitor->insertPlainText(event->text());

    qDebug() << event->key() << '\n';
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Q:
        setButtonDisable(ui->pushButton_Q);
        break;
    case Qt::Key_W:
        setButtonDisable(ui->pushButton_W);
        break;
    case Qt::Key_E:
        setButtonDisable(ui->pushButton_E);
        break;
    case Qt::Key_R:
        setButtonDisable(ui->pushButton_R);
        break;
    case Qt::Key_T:
        setButtonDisable(ui->pushButton_T);
        break;
    case Qt::Key_Y:
        setButtonDisable(ui->pushButton_Y);
        break;
    case Qt::Key_U:
        setButtonDisable(ui->pushButton_U);
        break;
    case Qt::Key_I:
        setButtonDisable(ui->pushButton_I);
        break;
    case Qt::Key_O:
        setButtonDisable(ui->pushButton_O);
        break;
    case Qt::Key_P:
        setButtonDisable(ui->pushButton_P);
        break;
    case Qt::Key_G1:
        setButtonDisable(ui->pushButton_G1);
        break;
    case Qt::Key_Udiaeresis:
        setButtonDisable(ui->pushButton_U1);
        break;
    case Qt::Key_A:
        setButtonDisable(ui->pushButton_A);
        break;
    case Qt::Key_S:
        setButtonDisable(ui->pushButton_S);
        break;
    case Qt::Key_D:
        setButtonDisable(ui->pushButton_D);
        break;
    case Qt::Key_F:
        setButtonDisable(ui->pushButton_F);
        break;
    case Qt::Key_G:
        setButtonDisable(ui->pushButton_G);
        break;
    case Qt::Key_H:
        setButtonDisable(ui->pushButton_H);
        break;
    case Qt::Key_J:
        setButtonDisable(ui->pushButton_J);
        break;
    case Qt::Key_K:
        setButtonDisable(ui->pushButton_K);
        break;
    case Qt::Key_L:
        setButtonDisable(ui->pushButton_L);
        break;
    case Qt::Key_S1:
        setButtonDisable(ui->pushButton_S1);
        break;
    case Qt::Key_Z:
        setButtonDisable(ui->pushButton_Z);
        break;
    case Qt::Key_X:
        setButtonDisable(ui->pushButton_X);
        break;
    case Qt::Key_C:
        setButtonDisable(ui->pushButton_C);
        break;
    case Qt::Key_V:
        setButtonDisable(ui->pushButton_V);
        break;
    case Qt::Key_B:
        setButtonDisable(ui->pushButton_B);
        break;
    case Qt::Key_N:
        setButtonDisable(ui->pushButton_N);
        break;
    case Qt::Key_M:
        setButtonDisable(ui->pushButton_M);
        break;
    case Qt::Key_Odiaeresis:
        setButtonDisable(ui->pushButton_O1);
        break;
    case Qt::Key_Ccedilla:
        setButtonDisable(ui->pushButton_C1);
        break;
    case Qt::Key_Exclam:
        setButtonDisable(ui->pushButton_Ex);
        break;
    case Qt::Key_Apostrophe:
        setButtonDisable(ui->pushButton_Quote);
        break;
    case Qt::Key_Hat:
        setButtonDisable(ui->pushButton_XOR);
        break;
    case Qt::Key_AsciiCircum:
        setButtonDisable(ui->pushButton_Hash);
        break;
    case Qt::Key_Plus:
        setButtonDisable(ui->pushButton_Add);
        break;
    case Qt::Key_Dollar:
        setButtonDisable(ui->pushButton_Dolar);
        break;
    case Qt::Key_Percent:
        setButtonDisable(ui->pushButton_Mod);
        break;
    case Qt::Key_Ampersand:
        setButtonDisable(ui->pushButton_Addr);
        break;
    case Qt::Key_Slash:
        setButtonDisable(ui->pushButton_Slash);
        break;
    case Qt::Key_BraceLeft:
        setButtonDisable(ui->pushButton_LCurly);
        break;
    case Qt::Key_ParenLeft:
        setButtonDisable(ui->pushButton_LParanthesis);
        break;
    case Qt::Key_BracketLeft:
        setButtonDisable(ui->pushButton_LIndex);
        break;
    case Qt::Key_ParenRight:
        setButtonDisable(ui->pushButton_RParanthesis);
        break;
    case Qt::Key_BracketRight:
        setButtonDisable(ui->pushButton_RIndex);
        break;
    case Qt::Key_Equal:
        setButtonDisable(ui->pushButton_Equal);
        break;
    case Qt::Key_BraceRight:
        setButtonDisable(ui->pushButton_RCurly);
        break;
    case Qt::Key_Question:
        setButtonDisable(ui->pushButton_Question);
        break;
    case Qt::Key_Asterisk:
        setButtonDisable(ui->pushButton_Asterix);
        break;
    case Qt::Key_Backslash:
        setButtonDisable(ui->pushButton_BackSlash);
        break;
    case Qt::Key_QuoteDbl:
        setButtonDisable(ui->pushButton_2Quote);
        break;
    case Qt::Key_Underscore:
        setButtonDisable(ui->pushButton_Underscore);
        break;
    case Qt::Key_Minus:
        setButtonDisable(ui->pushButton_Hyphen);
        break;
    case Qt::Key_AsciiTilde:
        setButtonDisable(ui->pushButton_Tilda);
        break;
    case Qt::Key_Semicolon:
        setButtonDisable(ui->pushButton_SColon);
        break;
    case Qt::Key_Comma:
        setButtonDisable(ui->pushButton_Comma);
        break;
    case Qt::Key_Colon:
        setButtonDisable(ui->pushButton_Colon);
        break;
    case Qt::Key_Period:
        setButtonDisable(ui->pushButton_Dot);
        break;
    case Qt::Key_Greater:
        setButtonDisable(ui->pushButton_RS);
        break;
    case Qt::Key_Less:
        setButtonDisable(ui->pushButton_LS);
        break;
    case Qt::Key_Bar:
        setButtonDisable(ui->pushButton_OR);
        break;
    case Qt::Key_Enter:
        setButtonDisable(ui->pushButton_ENT);
        break;
    case Qt::Key_Return:
        setButtonDisable(ui->pushButton_ENT);
        break;
    case Qt::Key_Delete:
        setButtonDisable(ui->pushButton_DEL);
        break;
    case Qt::Key_Space:
        setButtonDisable(ui->pushButton_SP);
        break;
    case Qt::Key_0:
        setButtonDisable(ui->pushButton_0);
        break;
    case Qt::Key_1:
        setButtonDisable(ui->pushButton_1);
        break;
    case Qt::Key_2:
        setButtonDisable(ui->pushButton_2);
        break;
    case Qt::Key_3:
        setButtonDisable(ui->pushButton_3);
        break;
    case Qt::Key_4:
        setButtonDisable(ui->pushButton_4);
        break;
    case Qt::Key_5:
        setButtonDisable(ui->pushButton_5);
        break;
    case Qt::Key_6:
        setButtonDisable(ui->pushButton_6);
        break;
    case Qt::Key_7:
        setButtonDisable(ui->pushButton_7);
        break;
    case Qt::Key_8:
        setButtonDisable(ui->pushButton_8);
        break;
    case Qt::Key_9:
        setButtonDisable(ui->pushButton_9);
        break;
    default:
        break;
    }
}
