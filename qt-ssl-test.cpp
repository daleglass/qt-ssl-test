#include <QCoreApplication>
#include <QtNetwork/QSslSocket>
#include <iostream>

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   std::cout << "SSL support:" << (QSslSocket::supportsSsl() ? "True" : "False") <<    std::endl;QSslSocket socket;

   socket.connectToHostEncrypted("doc.qt.io", 443);
   if (!socket.waitForEncrypted()) {
      std::cout << socket.errorString().toStdString() << std::endl;
      return 1;
   }

   socket.write("GET / HTTP/1.0\r\n\r\n");
   while (socket.waitForReadyRead())
      std::cout << socket.readAll().data() << std::endl;

   a.exit(0);   
   return a.exec();
}

