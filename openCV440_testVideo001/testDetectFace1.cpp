#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

using namespace cv;
using namespace std;

constexpr auto CV_AA = 16;

int testDetectFace1()
{
    CascadeClassifier cascade;
    cascade.load("D:\\OneDrive\\Programing\\openCV\\lbpcascade_frontalface.xml"); //正面顔情報が入っているカスケードファイル読み込み
 //   cascade.load("D:\\OneDrive\\Programing\\openCV\\haarcascade_frontalface_alt.xml"); //正面顔情報が入っているカスケードファイル読み込み
    Mat img = imread("D:\\OneDrive\\Programing\\openCV\\lena.png", IMREAD_UNCHANGED); //入力画像読み込み
    vector<Rect> faces; //輪郭情報を格納場所
    cascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(20, 20)); //カスケードファイルに基づいて顔を検知する．検知した顔情報をベクトルfacesに格納

    for (int i = 0; i < faces.size(); i++) //検出した顔の個数"faces.size()"分ループを行う
    {
        rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, CV_AA); //検出した顔を赤色矩形で囲む
    }

    imshow("detect face", img);
    waitKey(0);

    return 0;
}