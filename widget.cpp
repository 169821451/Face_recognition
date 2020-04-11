#include "widget.h"
#include "ui_widget.h"






Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



//    char* APPID = "8s22FzspXbsRQHoE9a4AAAUPUJN2DNixFEhtntPTSQnq";
//    char* SDKKey = "3ibZEtk5MdMAzBtTLHxUzwR1A6DGghS37UmEqWbk3i98";
    char APPID[] = "8s22FzspXbsRQHoE9a4AAAUPUJN2DNixFEhtntPTSQnq";
    char* appID = APPID;
    char SDKKey[] = "3ibZEtk5MdMAzBtTLHxUzwR1A6DGghS37UmEqWbk3i98";
    char* sdkKey = SDKKey;
    // 激活虹软 SDK
    MRESULT res = ASFOnlineActivation(APPID,SDKKey);
    if(MOK != res && MERR_ASF_BASE_ALREADY_ACTIVATED != res)
    {
        printf("ALActivation fail: %d\n", res);

        return;
    }else
    {
        printf("ALActivation sucess: %d\n", res);
    }
    // 初始化识别引擎
    MHandle handle = NULL;
    MInt32 nScale = 32;
    MInt32 faceNum = 5;
    MInt32 mask = ASF_FACE_DETECT | ASF_FACERECOGNITION | ASF_AGE | ASF_GENDER | ASF_FACE3DANGLE;
    // 引擎初始化参数一为设置为视频模式
    MRESULT InitRes = ASFInitEngine(ASF_DETECT_MODE_VIDEO,ASF_OP_0_ONLY,16,5,mask,&handle);
    if(InitRes != MOK)
        QMessageBox::warning(nullptr,"错误","初始化失败！",QMessageBox::Ok);
    else 
        QMessageBox::information(nullptr,"成功","初始化成功!",QMessageBox::Ok);

    // 人脸检测
    VideoCapture cap;
    cap.open("F:/CPPPritice/VS_QT/Face_recognition/1.mp4");


    

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 点击加载视频

    namedWindow("video",WINDOW_AUTOSIZE);

    VideoCapture cap;
    cap.open("F:/CPPPritice/VS_QT/Face_recognition/1.mp4");
    Mat frame;
    while (1)
    {
        cap >> frame;
        if(frame.empty())
            break;
        imshow("video",frame);
        if(waitKey(33) >= 0)
            break;

    }

}
