#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

class GraphicApplication : public QWidget {
public:
	GraphicApplication(QWidget* parent = nullptr) :QWidget(parent) {
		// Элементы интерфейса
		frequencyLineEdit = new QLineEdit;
		attenuationLineEdit = new QLineEdit;
		connectButton = new QPushButton("Соединение");
		applyButton = new QPushButton("Применить");
		connectionStatusLabel = new QLabel("Нет соединения");
		errorLogLabel = new QLabel;

		// Компоновщики для размещения элементов интерфейса
		QVBoxLayout* mainLayout = new QVBoxLayout;
		QHBoxLayout* frequencyLayout = new QHBoxLayout;
		QVBoxLayout* attenuationLayout = new QVBoxLayout;
		QVBoxLayout* buttonLayout = new QVBoxLayout;

		//размещение элементов в компоновщиках.
		frequencyLayout->addWidget(new QLabel("Частота"));
		frequencyLayout->addWidget(frequencyLineEdit);
		attenuationLayout->addWidget(new QLabel("Затухание"));
		attenuationLayout->addWidget(attenuationLineEdit);
		buttonLayout->addWidget(connectButton);
		buttonLayout->addWidget(applyButton);
		mainLayout->addLayout(frequencyLayout);
		mainLayout->addLayout(attenuationLayout);
		mainLayout->addWidget(connectionStatusLabel);
		mainLayout->addWidget(errorLogLabel);
		mainLayout->addLayout(buttonLayout);

		// Основной компоновщик для окна приложения
		setLayout(mainLayout);

		// Подключение сигналов и слотов
		connect(connectButton, &QPushButton::clicked, this, &GraphicApplication::connectDevice);
		connect(applyButton, &QPushButton::clicked, this, &GraphicApplication::applySettings);
	}

	bool connectToDevice(const QString& ipAddress, int port) {
		QByteArray ipAddressBytes = ipAddress.toUtf8();
		const char* ipAddressStr = ipAddressBytes.constData();
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			std::cerr << "Не удалось инициализировать библиотеку Winsock\n";
			return false;
		}
		SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
		struct sockaddr_in servaddr {};
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(port);
		if (inet_pton(AF_INET, ipAddressStr, &(servaddr.sin_addr)) <= 0) {
			std::cerr << "Некорректный IP-адрес\n";
			closesocket(sockfd);
			WSACleanup();
			return false;
		}
		closesocket(sockfd);
		WSACleanup();
		return true;
	}

	QString getIpAddress() {
		QString ipAddress = "192.168.0.1";
	}

	int getPort() {
		return 1234;
	}

private slots:
	void connectDevice() {
		QString ipAddress = getIpAddress();
		int port = getPort();
		bool isConnected = connectToDevice(ipAddress, port);
		if (isConnected) {
			connectionStatusLabel->setText("Подключено!");
		}
		else
		{
			QMessageBox::warning(this, "Подключение не удалось.", "Произошла ошибка при подключении.Проверьте данные и устройство.");
		}
	}

	void applySettings() {
		QString frequency = frequencyLineEdit->text();
		QString attenuation = attenuationLineEdit->text();

		QMessageBox::information(this, "Настройки применены!", "Настройки успешно применены!");
	}

private:
	QLineEdit* frequencyLineEdit;  // Поле ввода частоты
	QLineEdit* attenuationLineEdit; // Поле ввода аттенюации
	QPushButton* connectButton; // Кнопка подключения
	QPushButton* applyButton; // Кнопка применения настроек
	QLabel* connectionStatusLabel;  // Индикация статуса подключения
	QLabel* errorLogLabel; // Журнал ошибок

};

int main(int args, char* argv[]) {
	QApplication app(args, argv);

	GraphicApplication graphicApp;
	graphicApp.show();
	return app.exec();
}