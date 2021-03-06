﻿#include "CommonHelper.h"

#include <QFile>
#include <QApplication>
#include <QDateTime>
#include <QStandardPaths>
#include <QSettings>
#include <QDir>
#include <QPainter>
#include <QBitmap>

CommonHelper::CommonHelper()
{

}

void CommonHelper::loadAppStyle(const QString &style)
{
    QFile file(style);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = QString(file.readAll());
        qApp->setStyleSheet(styleSheet);
        file.close();
    }
}

QImage CommonHelper::toGray(QImage image)
{
    int height = image.height();
    int width = image.width();
    QImage ret = QImage(width, height, QImage::Format_Indexed8);

    ret.setColorCount(256);

    for (int i = 0; i < 256; i++)
    {
        ret.setColor(i, qRgb(i, i, i));
    }

    switch (image.format()) {
    case QImage::Format_Indexed8:
    {
        for (int i = 0; i < height; i++)
        {
            const uchar *pSrc = (uchar*)image.constScanLine(i);
            uchar *pDst = (uchar*)ret.scanLine(i);
            memcpy(pDst, pSrc, width);
        }
    }
        break;

    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied:
    {
        for (int i = 0; i < height; i++)
        {
            const QRgb *pSrc = (QRgb*)image.constScanLine(i);
            uchar *pDst = (uchar*)ret.scanLine(i);
            for (int j = 0; j < width; j++)
            {
                pDst[j] = qGray(pSrc[j]);
            }
        }
    }
        break;

    default:
        break;
    }

    return ret;
}

QString CommonHelper::timeToString(qint64 time, QString format)
{
    QDateTime dateTime;
    return dateTime.fromTime_t(time).toString(format);
}

QString CommonHelper::tempDir()
{
    QString appName =  QCoreApplication::applicationName();
    QString sysTempPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    QString myTempPath = sysTempPath + "/" + appName;

    QDir dir(myTempPath);
    if (!dir.exists())
    {
        dir.mkpath(myTempPath);
    }

    return myTempPath;
}

QString CommonHelper::userTempPath()
{
    QString userId = readSetting(kSettingLoginUserId).toString();
    if (userId.isEmpty())
    {
        return QString("");
    }

    QString tempPath = tempDir() + "/" + userId;
    QDir dir(tempPath);
    if (!dir.exists())
    {
        dir.mkpath(tempPath);
    }

    return tempPath;
}

QString CommonHelper::dataDir()
{
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);

    QDir dir(dataPath);
    if (!dir.exists())
    {
        dir.mkpath(dataPath);
    }

    return dataPath;
}

QString CommonHelper::userDataPath()
{
    QString userId = readSetting(kSettingLoginUserId).toString();
    if (userId.isEmpty())
    {
        return QString();
    }
    QString dataPath = dataDir() + "/" + userId;
    QDir dir(dataPath);
    if (!dir.exists())
    {
        dir.mkpath(dataPath);
    }

    return dataPath;
}

void CommonHelper::saveSetting(const SettingKey &key, const QVariant &value)
{
    QString iniName = QCoreApplication::applicationName() + ".ini";
    QSettings settings(dataDir() + "/" + iniName, QSettings::IniFormat);

    switch (key)
    {
    case kSettingLoginUserId:
    {
        settings.beginGroup("Login");
        settings.setValue("userId", value);
        settings.endGroup();
    }
        break;

    case kSettingLoginUserName:
    {
        settings.beginGroup("Login");
        settings.setValue("name", value);
        settings.endGroup();
    }
        break;

    case kSettingLoginPwd:
    {
        QString pwd = value.toString();
        settings.beginGroup("Login");
        settings.setValue("pwd", QString(pwd.toLocal8Bit().toBase64()));
        settings.endGroup();
    }
        break;

    case kSettingLoginTime:
    {
        settings.beginGroup("Login");
        settings.setValue("time", value);
        settings.endGroup();
    }
        break;

    case kSettingSummitPwd:
    {
        QString pwd = value.toString();
        settings.beginGroup("Login");
        settings.setValue("summitpwd", QString(pwd.toLocal8Bit().toBase64()));
        settings.endGroup();
    }
        break;

    case kSettingLoginToken:
    {
        settings.beginGroup("Login");
        settings.setValue("token", value);
        settings.endGroup();
    }
        break;

    case kSettingLoginHeadUrl:
    {
        settings.beginGroup("Login");
        settings.setValue("headUrl", value);
        settings.endGroup();
    }
        break;

    case kSettingLoginEnv:
    {
        settings.beginGroup("Login");
        settings.setValue("onLineEnv", value);
        settings.endGroup();
    }
        break;

    case kSettingLoginKeepPwd:
    {
        settings.beginGroup("Login");
        settings.setValue("KeepPwd", value);
        settings.endGroup();
    }
        break;

    case kSettingContactVersion:
    {
        settings.beginGroup("Contact");
        settings.setValue("version", value);
        settings.endGroup();
    }
        break;

    default:
        break;
    }
}

QVariant CommonHelper::readSetting(const SettingKey &key)
{
    QString iniName = QCoreApplication::applicationName() + ".ini";
    QSettings settings(dataDir() + "/" + iniName, QSettings::IniFormat);

    QVariant value;

    switch (key)
    {
    case kSettingLoginUserId:
    {
        settings.beginGroup("Login");
        value = settings.value("userId", "");
        settings.endGroup();
    }
        break;

    case kSettingLoginUserName:
    {
        settings.beginGroup("Login");
        value = settings.value("name", "");
        settings.endGroup();
    }
        break;

    case kSettingLoginPwd:
    {
        settings.beginGroup("Login");
        QString pwdBase64 = settings.value("pwd", "").toString();
        value = QString(QByteArray::fromBase64(pwdBase64.toLocal8Bit()));
        settings.endGroup();
    }
        break;

    case kSettingLoginTime:
    {
        settings.beginGroup("Login");
        value = settings.value("time", "");
        settings.endGroup();
    }
        break;

    case kSettingSummitPwd:
    {
        settings.beginGroup("Login");
        QString pwdBase64 = settings.value("summitpwd", "").toString();
        value = QString(QByteArray::fromBase64(pwdBase64.toLocal8Bit()));
        settings.endGroup();
    }
        break;

    case kSettingLoginToken:
    {
        settings.beginGroup("Login");
        value = settings.value("token", "");
        settings.endGroup();
    }
        break;

    case kSettingLoginHeadUrl:
    {
        settings.beginGroup("Login");
        value = settings.value("headUrl", "");
        settings.endGroup();
    }
        break;

    case kSettingLoginEnv:
    {
        settings.beginGroup("Login");
        value = settings.value("onLineEnv", false);
        settings.endGroup();
    }
        break;

    case kSettingLoginKeepPwd:
    {
        settings.beginGroup("Login");
        value = settings.value("KeepPwd", false);
        settings.endGroup();
    }
        break;

    case kSettingContactVersion:
    {
        settings.beginGroup("Contact");
        value = settings.value("version", "");
        settings.endGroup();
    }
        break;

    default:
        break;
    }

    return value;
}

QString CommonHelper::encryptPwd(QString pwd)
{
    return QString(pwd.toLocal8Bit().toBase64());
}

QString CommonHelper::decryptPwd(QString encryptPwd)
{
    return QString(QByteArray::fromBase64(encryptPwd.toLocal8Bit()));
}

bool CommonHelper::copyFileToPath(const QString &fromDir,
                                  QString toDir,
                                  bool coverIfExist)
{
    toDir.replace("\\", "/");
    if (toDir == fromDir)
    {
        return true;
    }

    if (!QFile::exists(fromDir))
    {
        return false;
    }

    if (coverIfExist)
    {
        QDir createFile;
        if (createFile.exists(toDir))
        {
           createFile.remove(toDir) ;
        }
    }

    if (!QFile::copy(fromDir, toDir))
    {
        return false;
    }

    return true;
}

bool CommonHelper::copyDirectorFiles(const QString &fromDir,
                                     QString toDir,
                                     bool coverIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);

    ///< 如果目标目录不存在，则创建 >
    if (!targetDir.exists())
    {
        if (!targetDir.mkdir(targetDir.absolutePath()))
        {
            return false;
        }
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach (QFileInfo fileInfo, fileInfoList)
    {
        if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")
        {
            continue;
        }

        if (fileInfo.isDir())
        {
            if (!copyDirectorFiles(fileInfo.filePath(),
                                   targetDir.filePath(fileInfo.fileName()),
                                    coverIfExist))
            {
                return false;
            }
        }
        else
        {
            if (coverIfExist && targetDir.exists(fileInfo.fileName()))
            {
                targetDir.remove(fileInfo.fileName());
            }

            if (!QFile::copy(fileInfo.filePath(),
                             targetDir.filePath(fileInfo.fileName())))
            {
                return false;
            }
        }

    }

    return true;
}

QImage CommonHelper::compressImage(const QImage &sourceImage,
                                   const int maxSizeInBytes,
                                   const QSize &targetSize)
{
    if ((sourceImage.size().width() <= targetSize.width())
      && (sourceImage.size().height() <= targetSize.height()))
    {
        return sourceImage;
    }

    QImage srcImage(sourceImage);
    int width = 800;
    int height = (srcImage.height() * width) / srcImage.width();
    QImage result = srcImage.scaled(800, height, Qt::KeepAspectRatio, Qt::FastTransformation)
                            .scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QString tmpImgPath = userTempPath() + QString("/%1.jpg").arg(QDateTime::currentMSecsSinceEpoch());
    result.save(tmpImgPath, "JPEG", 100);

    QFile imgFile(tmpImgPath);
    int fileSize = imgFile.size();

    int quality = 100;
    while (fileSize > maxSizeInBytes)
    {
        quality = quality - 5;
        result.save(tmpImgPath, "JPEG", 100);
        fileSize = imgFile.size();

        if (quality <= 0)
        {
            break;
        }
    }

    QImage targetImg(tmpImgPath);

    QDir tmpDir;
    if (tmpDir.exists(tmpImgPath))
    {
        tmpDir.remove(tmpImgPath);
    }
    return targetImg;
}

QPixmap CommonHelper::PixmapToRound(QPixmap &src, QSize size)
{
    if (src.isNull())
    {
        return QPixmap();
    }

    QImage resultImage(size, QImage::Format_ARGB32_Premultiplied);
    QPixmap head_mask(":/Resources/Headers/mask.png");

    QPainter painter(&resultImage);

    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resultImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawPixmap(0, 0, head_mask.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    painter.setCompositionMode(QPainter::CompositionMode_SourceOut);
    painter.drawPixmap(0, 0, src.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.end();

    src = QPixmap::fromImage(resultImage);

    return src;
}

