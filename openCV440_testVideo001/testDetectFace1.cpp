#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

using namespace cv;
using namespace std;

constexpr auto CV_AA = 16;

int testDetectFace1()
{
    CascadeClassifier cascade;
    cascade.load("D:\\OneDrive\\Programing\\openCV\\lbpcascade_frontalface.xml"); //���ʊ��񂪓����Ă���J�X�P�[�h�t�@�C���ǂݍ���
 //   cascade.load("D:\\OneDrive\\Programing\\openCV\\haarcascade_frontalface_alt.xml"); //���ʊ��񂪓����Ă���J�X�P�[�h�t�@�C���ǂݍ���
    Mat img = imread("D:\\OneDrive\\Programing\\openCV\\lena.png", IMREAD_UNCHANGED); //���͉摜�ǂݍ���
    vector<Rect> faces; //�֊s�����i�[�ꏊ
    cascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(20, 20)); //�J�X�P�[�h�t�@�C���Ɋ�Â��Ċ�����m����D���m����������x�N�g��faces�Ɋi�[

    for (int i = 0; i < faces.size(); i++) //���o������̌�"faces.size()"�����[�v���s��
    {
        rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, CV_AA); //���o�������ԐF��`�ň͂�
    }

    imshow("detect face", img);
    waitKey(0);

    return 0;
}