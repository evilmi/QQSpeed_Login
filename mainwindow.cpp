#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdir.h>
#include <QMessageBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置窗口图标
    this->setWindowIcon(QIcon(":/icon/speed.ico"));

    // 设置窗口标题
    this->setWindowTitle("QQ飞车");

    // 禁止最大化按钮
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

    // 禁止拖动窗口大小
    setFixedSize(this->width(),this->height());

    // 设置窗口无边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    my_web = new QWebEngineView(this);
    ui->verticalLayout->addWidget(my_web);
    my_web->load(QUrl("file:///" + QDir::currentPath() + "/LoaderNew/web/loader.html"));
    //my_web->load(QUrl("https://evilmi.github.io/"));

    //最小化窗口
    connect(ui->pButtonMin, &QPushButton::clicked, this,&QWidget::showMinimized);

    //关闭窗口
    connect(ui->pButtonClose,&QPushButton::clicked,this,&QWidget::close);

    //登录
    connect(ui->pButtonLogin, &QPushButton::clicked,[=](){
        //登录
        Login();
    });

    //qDebug()<<"当前路径"<<QDir::currentPath();

    //因为没有使用预加载技术一开始网页会显示空白 所以这里需要延迟一段时间
    //等待网页加载完成后再显示窗口就同步了
    sleep(2000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sleep(unsigned int msec){
    //currnentTime 返回当前时间 用当前时间加上我们要延时的时间msec得到一个新的时刻
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    //用while循环不断比对当前时间与我们设定的时间
    while(QTime::currentTime()<reachTime){
        //如果当前的系统时间尚未达到我们设定的时刻，就让Qt的应用程序类执行默认的处理，
        //以使程序仍处于响应状态。一旦到达了我们设定的时刻，就跳出该循环，继续执行后面的语句。
        QApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void MainWindow::Login()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
}
