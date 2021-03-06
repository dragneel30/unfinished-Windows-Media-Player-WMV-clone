#ifndef MYMUSICPLAYER_H
#define MYMUSICPLAYER_H


#include <QMediaPlayer>
#include <QObject>
#include <QTimer>
#include <QDebug>
class MyMusicPlayer : public QObject
{
    Q_OBJECT
public:
    MyMusicPlayer();
    MyMusicPlayer(QString);
    ~MyMusicPlayer();
    QMediaPlayer* getAudio() const;
    const QString& getName() const;
    qint32 durationToMinute(qint64); //helper function
private:
    QMediaPlayer* audio;
    QString name;
public slots:
    void play(QString);
    void pause();
    void stop();
    void resume(); // separate from pause function for understandability
    void skipPosition(int);
signals:
    void durationRequested(qint32,qint32);
    void played(bool);
};

#endif // MYMUSICPLAYER_H
