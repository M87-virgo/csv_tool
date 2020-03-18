#include <QDebug>
#include <QIODevice>
#include <QThread>

#include <csv_writedata_teamType.h>
#include <csv_writedata_playerType.h>
#include <csv_writedata_rest.h>

template <class T>
void writeData(QVector<T> &vec, const QString fp, void(T::*method_ptr)(QFile&) )
{
    QFile f(fp);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append) )
    {
        qDebug() << "File error" << f.error();
    }
    else
    {
        QThread::currentThread();
        for(T &tw : vec)
        {
            //tw.writeTeams(f);
            (tw.*method_ptr)(f);
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
