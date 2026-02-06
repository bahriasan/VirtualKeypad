#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

static bool CapsLockActive = false;

static void setButtonEnable(QPushButton* btn)
{
    QPalette plt_enable = QPalette(Qt::GlobalColor::darkGray);
    btn->setPalette(plt_enable);
}

static void setButtonDisable(QPushButton* btn)
{
    QPalette plt_disable = QPalette(Qt::GlobalColor::color0);
    btn->setPalette(plt_disable);
}

static void setHoverEnable(QPushButton* btn)
{
    QPalette plt_enable = QPalette(Qt::GlobalColor::lightGray);
    btn->setPalette(plt_enable);
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
//    setButtonDisable(ui->pushButton_G1);
//    setButtonDisable(ui->pushButton_U1);
    setButtonDisable(ui->pushButton_A);
    setButtonDisable(ui->pushButton_S);
    setButtonDisable(ui->pushButton_D);
    setButtonDisable(ui->pushButton_F);
    setButtonDisable(ui->pushButton_G);
    setButtonDisable(ui->pushButton_H);
    setButtonDisable(ui->pushButton_J);
    setButtonDisable(ui->pushButton_K);
    setButtonDisable(ui->pushButton_L);
 //   setButtonDisable(ui->pushButton_S1);
 //   setButtonDisable(ui->pushButton_I1);
    setButtonDisable(ui->pushButton_Z);
    setButtonDisable(ui->pushButton_X);
    setButtonDisable(ui->pushButton_C);
    setButtonDisable(ui->pushButton_V);
    setButtonDisable(ui->pushButton_B);
    setButtonDisable(ui->pushButton_N);
    setButtonDisable(ui->pushButton_M);
 //   setButtonDisable(ui->pushButton_O1);
 //   setButtonDisable(ui->pushButton_C1);
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
    setButtonDisable(ui->pushButton_Close);
    setHoverEnable(ui->pushButton_Touch);
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
    TouchPad = false;

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
    QObject::connect(ui->pushButton_Touch, &QAbstractButton::pressed, this, &MainWindow::toggleTouchPad);



    //Make MainWindow transparent
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_NoSystemBackground, true);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    //Disable Text Edit
    ui->monitor->setAttribute(Qt::WA_WState_Hidden, true);

    this->setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleTouchPad()
{
    if(true == TouchPad)
    {
        TouchPad = false;
        QPalette plt_enable = QPalette(Qt::GlobalColor::lightGray);
        ui->pushButton_Touch->setPalette(plt_enable);
    }
    else
    {
        TouchPad = true;
        QPalette plt_enable = QPalette(Qt::GlobalColor::darkGray);
        ui->pushButton_Touch->setPalette(plt_enable);
    }
}

bool MainWindow::isTouchPad()
{
    return TouchPad;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(true == TouchPad)
    {
        if(Qt::NoModifier == event->modifiers())
        {
            switch(event->key())
            {
            case Qt::Key_F1:
                setButtonEnable(ui->pushButton_Q);
                break;
            case Qt::Key_F2:
                setButtonEnable(ui->pushButton_W);
                break;
            case Qt::Key_F3:
                setButtonEnable(ui->pushButton_E);
                break;
            case Qt::Key_F4:
                setButtonEnable(ui->pushButton_R);
                break;
            case Qt::Key_F5:
                setButtonEnable(ui->pushButton_T);
                break;
            case Qt::Key_F6:
                setButtonEnable(ui->pushButton_Y);
                break;
            case Qt::Key_F7:
                setButtonEnable(ui->pushButton_U);
                break;
            case Qt::Key_F8:
                setButtonEnable(ui->pushButton_I);
                break;
            case Qt::Key_F9:
                setButtonEnable(ui->pushButton_O);
                break;
            case Qt::Key_F10:
                setButtonEnable(ui->pushButton_P);
                break;
            case Qt::Key_F11:
                setButtonEnable(ui->pushButton_A);
                break;
            case Qt::Key_F12:
                setButtonEnable(ui->pushButton_S);
                break;
            default:
                break;
            }
        }
        else if(Qt::ShiftModifier == event->modifiers())
        {
            switch(event->key())
            {
            case Qt::Key_F1:
                setButtonEnable(ui->pushButton_D);
                break;
            case Qt::Key_F2:
                setButtonEnable(ui->pushButton_F);
                break;
            case Qt::Key_F3:
                setButtonEnable(ui->pushButton_G);
                break;
            case Qt::Key_F4:
                setButtonEnable(ui->pushButton_H);
                break;
            case Qt::Key_F5:
                setButtonEnable(ui->pushButton_J);
                break;
            case Qt::Key_F6:
                setButtonEnable(ui->pushButton_K);
                break;
            case Qt::Key_F7:
                setButtonEnable(ui->pushButton_L);
                break;
            case Qt::Key_F8:
                setButtonEnable(ui->pushButton_Z);
                break;
            case Qt::Key_F9:
                setButtonEnable(ui->pushButton_X);
                break;
            case Qt::Key_F10:
                setButtonEnable(ui->pushButton_C);
                break;
            case Qt::Key_F11:
                setButtonEnable(ui->pushButton_V);
                break;
            case Qt::Key_F12:
                setButtonEnable(ui->pushButton_B);
                break;
            default:
                break;
            }
        }
        else if(Qt::ControlModifier == event->modifiers())
        {
            switch(event->key())
            {
            case Qt::Key_F1:
                setButtonEnable(ui->pushButton_N);
                break;
            case Qt::Key_F2:
                setButtonEnable(ui->pushButton_M);
                break;
            case Qt::Key_F3:
                setButtonEnable(ui->pushButton_1);
                break;
            case Qt::Key_F4:
                setButtonEnable(ui->pushButton_2);
                break;
            case Qt::Key_F5:
                setButtonEnable(ui->pushButton_3);
                break;
            case Qt::Key_F6:
                setButtonEnable(ui->pushButton_4);
                break;
            case Qt::Key_F7:
                setButtonEnable(ui->pushButton_5);
                break;
            case Qt::Key_F8:
                setButtonEnable(ui->pushButton_6);
                break;
            case Qt::Key_F9:
                setButtonEnable(ui->pushButton_7);
                break;
            case Qt::Key_F10:
                setButtonEnable(ui->pushButton_8);
                break;
            case Qt::Key_F11:
                setButtonEnable(ui->pushButton_9);
                break;
            case Qt::Key_F12:
                setButtonEnable(ui->pushButton_0);
                break;
            default:
                break;
            }
        }
        else
        {   /*Do Nothing*/  }
    }
    else    //Hover Mode
    {
        if(Qt::NoModifier == event->modifiers())
        {
            switch(event->key())
            {
            case Qt::Key_F1:
                setHoverEnable(ui->pushButton_Q);
                break;
            case Qt::Key_F2:
                setHoverEnable(ui->pushButton_W);
                break;
            case Qt::Key_F3:
                setHoverEnable(ui->pushButton_E);
                break;
            case Qt::Key_F4:
                setHoverEnable(ui->pushButton_R);
                break;
            case Qt::Key_F5:
                setHoverEnable(ui->pushButton_T);
                break;
            case Qt::Key_F6:
                setHoverEnable(ui->pushButton_Y);
                break;
            case Qt::Key_F7:
                setHoverEnable(ui->pushButton_U);
                break;
            case Qt::Key_F8:
                setHoverEnable(ui->pushButton_I);
                break;
            case Qt::Key_F9:
                setHoverEnable(ui->pushButton_O);
                break;
            case Qt::Key_F10:
                setHoverEnable(ui->pushButton_P);
                break;
            case Qt::Key_F11:
                setHoverEnable(ui->pushButton_A);
                break;
            case Qt::Key_F12:
                setHoverEnable(ui->pushButton_S);
                break;
            default:
                break;
            }
        }
        else if(Qt::ShiftModifier == event->modifiers())
        {
            switch(event->key())
            {
            case Qt::Key_F1:
                setHoverEnable(ui->pushButton_D);
                break;
            case Qt::Key_F2:
                setHoverEnable(ui->pushButton_F);
                break;
            case Qt::Key_F3:
                setHoverEnable(ui->pushButton_G);
                break;
            case Qt::Key_F4:
                setHoverEnable(ui->pushButton_H);
                break;
            case Qt::Key_F5:
                setHoverEnable(ui->pushButton_J);
                break;
            case Qt::Key_F6:
                setHoverEnable(ui->pushButton_K);
                break;
            case Qt::Key_F7:
                setHoverEnable(ui->pushButton_L);
                break;
            case Qt::Key_F8:
                setHoverEnable(ui->pushButton_Z);
                break;
            case Qt::Key_F9:
                setHoverEnable(ui->pushButton_X);
                break;
            case Qt::Key_F10:
                setHoverEnable(ui->pushButton_C);
                break;
            case Qt::Key_F11:
                setHoverEnable(ui->pushButton_V);
                break;
            case Qt::Key_F12:
                setHoverEnable(ui->pushButton_B);
                break;
            default:
                break;
            }
        }
        else if(Qt::ControlModifier == event->modifiers())
        {
            switch(event->key())
            {
            case Qt::Key_F1:
                setHoverEnable(ui->pushButton_N);
                break;
            case Qt::Key_F2:
                setHoverEnable(ui->pushButton_M);
                break;
            case Qt::Key_F3:
                setHoverEnable(ui->pushButton_1);
                break;
            case Qt::Key_F4:
                setHoverEnable(ui->pushButton_2);
                break;
            case Qt::Key_F5:
                setHoverEnable(ui->pushButton_3);
                break;
            case Qt::Key_F6:
                setHoverEnable(ui->pushButton_4);
                break;
            case Qt::Key_F7:
                setHoverEnable(ui->pushButton_5);
                break;
            case Qt::Key_F8:
                setHoverEnable(ui->pushButton_6);
                break;
            case Qt::Key_F9:
                setHoverEnable(ui->pushButton_7);
                break;
            case Qt::Key_F10:
                setHoverEnable(ui->pushButton_8);
                break;
            case Qt::Key_F11:
                setHoverEnable(ui->pushButton_9);
                break;
            case Qt::Key_F12:
                setHoverEnable(ui->pushButton_0);
                break;
            default:
                break;
            }
        }
        else
        {   /*Do Nothing    */}
    }

    ui->monitor->moveCursor(QTextCursor::End);
    ui->monitor->insertPlainText(event->text());

    qDebug() << event->key() << '\n';
}


void MainWindow::keyReleaseEvent(QKeyEvent *event)
{  
    switch(event->key())
    {
    case Qt::Key_F1:
        setButtonDisable(ui->pushButton_Q);
        setButtonDisable(ui->pushButton_D);
        setButtonDisable(ui->pushButton_N);
        break;
    case Qt::Key_F2:
        setButtonDisable(ui->pushButton_W);
        setButtonDisable(ui->pushButton_F);
        setButtonDisable(ui->pushButton_M);
        break;
    case Qt::Key_F3:
        setButtonDisable(ui->pushButton_E);
        setButtonDisable(ui->pushButton_G);
        setButtonDisable(ui->pushButton_1);
        break;
    case Qt::Key_F4:
        setButtonDisable(ui->pushButton_R);
        setButtonDisable(ui->pushButton_H);
        setButtonDisable(ui->pushButton_2);
        break;
    case Qt::Key_F5:
        setButtonDisable(ui->pushButton_T);
        setButtonDisable(ui->pushButton_J);
        setButtonDisable(ui->pushButton_3);
        break;
    case Qt::Key_F6:
        setButtonDisable(ui->pushButton_Y);
        setButtonDisable(ui->pushButton_K);
        setButtonDisable(ui->pushButton_4);
        break;
    case Qt::Key_F7:
        setButtonDisable(ui->pushButton_U);
        setButtonDisable(ui->pushButton_L);
        setButtonDisable(ui->pushButton_5);
        break;
    case Qt::Key_F8:
        setButtonDisable(ui->pushButton_I);
        setButtonDisable(ui->pushButton_Z);
        setButtonDisable(ui->pushButton_6);
        break;
    case Qt::Key_F9:
        setButtonDisable(ui->pushButton_O);
        setButtonDisable(ui->pushButton_X);
        setButtonDisable(ui->pushButton_7);
        break;
    case Qt::Key_F10:
        setButtonDisable(ui->pushButton_P);
        setButtonDisable(ui->pushButton_C);
        setButtonDisable(ui->pushButton_8);
        break;
    case Qt::Key_F11:
        setButtonDisable(ui->pushButton_A);
        setButtonDisable(ui->pushButton_V);
        setButtonDisable(ui->pushButton_9);
        break;
    case Qt::Key_F12:
        setButtonDisable(ui->pushButton_S);
        setButtonDisable(ui->pushButton_B);
        setButtonDisable(ui->pushButton_0);
        break;
    default:
        break;
    }
}
