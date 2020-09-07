#include <opencv2/opencv.hpp>
#include <iostream>

#include <chrono>
#include <thread>


int testVideoCapture2() {
	//https://code-database.com/knowledges/96
	// ����t�@�C���̃p�X�̕�������i�[����I�u�W�F�N�g��錾����
	std::string filepath = "D:\\OneDrive\\Programing\\openCV\\P1020792.MP4";
	// ����t�@�C������荞�ނ��߂̃I�u�W�F�N�g��錾����
	cv::VideoCapture video;
	// ����t�@�C�����J��
	video.open(filepath);
	if (video.isOpened() == false) {
		// ����t�@�C�����J���Ȃ������Ƃ��͏I������
		return 0;
	}
	cv::VideoWriter writer; // ����t�@�C���������o�����߂̃I�u�W�F�N�g��錾����
	int fourcc = cv::VideoWriter::fourcc('m', 'p', '4', 'v'); // �r�f�I�t�H�[�}�b�g�̎w��( ISO MPEG-4 / .mp4)
	int    width, height; // , fourcc; // �쐬���铮��t�@�C���̐ݒ�
	double fps;
	width = (int)video.get(cv::CAP_PROP_FRAME_WIDTH);	// �t���[���������擾
	height = (int)video.get(cv::CAP_PROP_FRAME_HEIGHT);	// �t���[���c�����擾
	fps = video.get(cv::CAP_PROP_FPS);				// �t���[�����[�g���擾

	std::cout << "width:" << width << " , height:" << height << " , fps:" << fps << std::endl;

	//fps /= 6;

	writer.open("CloneVideo2.mp4", fourcc, fps, cv::Size(width, height));
	cv::Mat image;// �摜���i�[����I�u�W�F�N�g��錾����

	//int numFrame = 0;

	while (1) {
		//numFrame++;

		video >> image; // video����image��1�t���[������荞��

		//if (numFrame % 10 != 0)continue;
		//std::cout << numFrame << "\n";

		if (image.empty() == true) break; // �摜���ǂݍ��߂Ȃ������Ƃ��A�������[�v�𔲂���
		cv::imshow("showing", image); // �E�B���h�E�ɓ����\������
		writer << image;  // �摜 image �𓮉�t�@�C���֏����o��
		if (cv::waitKey(1) == 'q') break; //q�������ƏI��

		//std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}



}