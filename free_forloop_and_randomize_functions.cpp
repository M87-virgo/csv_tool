#include <QDebug>
#include <QIODevice>
#include <QThread>

#include <csv_writedata_teamType.h>
#include <csv_writedata_playerType.h>
#include <csv_writedata_rest.h>

void writeTeamsForLoop(QVector<teamType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(teamType &tw : vec)
        {
            tw.writeTeams(f);
        }
    }
    f.close();
}
void writeTeamDataForLoop(QVector<teamType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(teamType &t : vec)
        {
            t.writeTeamData(f);
        }
    }
    f.close();
}
void writeTeamKitsForLoop(QVector<teamType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(teamType &tk : vec)
        {
            tk.writeTeamKits(f);
        }
    }
    f.close();
}

void writePlayersDataForLoop(QVector<playerType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(playerType &p : vec)
        {
            p.writePlayersData(f);
        }
    }
    f.close();
}
void writePlayersDataForLoop2(QVector<playerType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(playerType &p : vec)
        {
            p.writePlayersData2(f);
        }
    }
    f.close();
}

void writeTeamCountryForLoop(QVector<teamCountryType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(teamCountryType &c : vec)
        {
            c.writeTeamCountry(f);
        }
    }
    f.close();
}
void writeTeamPlayerLinksForLoop(QVector<playerTeamType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(playerTeamType &tp : vec)
        {
            tp.writeTeamPlayerLinks(f);
        }
    }
    f.close();
}
void writeTextIdForLoop(QVector<textIdType> &vec, const QString &fp)
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(textIdType &tla : vec)
        {
            tla.writeTextId(f);
        }
    }
    f.close();
}

int randMemberUniform(std::default_random_engine &g, const int &a, const int &b)
{
    using Udistr = std::uniform_int_distribution<int>;
    Udistr rval{};

    return rval(g, Udistr::param_type{a, b} );
}
int randMemberPoisson(std::default_random_engine &g, const double &m)
{
    using Dstr = std::poisson_distribution<unsigned>;
    Dstr ranv{};

    return ranv(g, Dstr::param_type{m} );
}
auto randMemberBernoulli(std::default_random_engine &g, const double &m)
{
    using Bdistr = std::bernoulli_distribution;
    Bdistr rb{};

    return rb(g, Bdistr::param_type{m} );
}

int fetchesHighestId(QFile &f)
{
    int key = 0;
    QString line1;
    QString line2;
    if (!f.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File not exists";
    }
    else
    {
        QTextStream in(&f);
        while (!in.atEnd())
        {
            line1 = in.readLine();
            line2.swap(line1);

            QStringList item = line2.split('\t');

            key = item.at(0).toInt();
        }
        f.close();
    }
    return key;
}
