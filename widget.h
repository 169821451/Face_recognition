#ifndef WIDGET_H
#define WIDGET_H

// 设置中文
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>
#include <opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <arcsoft_face_sdk.h>
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <merror.h>
#include <amcomdef.h>
#include <QMessageBox>


#pragma comment(lib, "libarcsoft_face_engine.lib")
//#define APPID "8s22FzspXbsRQHoE9a4AAAUPUJN2DNixFEhtntPTSQnq"
//#define SDKKey "3ibZEtk5MdMAzBtTLHxUzwR1A6DGghS37UmEqWbk3i98"
#define MERR_ASF_BASE_ALREADY_ACTIVATED 90114 //SDK已激活
#define SafeFree(p) { if ((p)) free(p); (p) = NULL; }
#define SafeArrayDelete(p) { if ((p)) delete [] (p); (p) = NULL; }
#define SafeDelete(p) { if ((p)) delete (p); (p) = NULL; }




using namespace std;
using namespace cv;


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
