#include "dbustrans.h"
#include "mainwindow.h"

#include <QDebug>
#include <QDomDocument>
#include <QMessageBox>


void dbustrans::setUIWindow(MainWindow *w)
{
    m_mainWindow = w;
}

int dbustrans::setarg(QString _name, int _age, QString _phone, QString _id, QString _address, double _temp) {
    for (int i = 0; i < info.size(); i++) {
        if (_id == info[i][3]) {
            again = true;
            row = i;
            break;
        }
        again = false;
        qInfo() << "id:" << info[i][3];
        qInfo() << "info:" << info.size();
    }
//    qInfo() << again;
    if (again == true) {

        qInfo() << "row:" << row;
        if (_age > 200 || _age < 0) {
            return 3;
        }
        else if (_temp > 42 || _temp < 34) {
            return 4;
        }
        else if (_phone.length() != 11) {
            return 5;
        }
        else if (_id.length() != 18) {
            return 6;
        }
        m_mainWindow->updaterow(row, _name, _age, _phone, _id, _address, _temp);
        name = _name;
        age = _age;
        phone = _phone;
        id = _id;
        address = _address;
        temp = _temp;
        info[row][0] = name;
        info[row][1] = QString::number(age);
        info[row][2] = phone;
        info[row][3] = id;
        info[row][4] = address;
        info[row][5] = QString::number(temp);
        qInfo() << "xml";
        if (temp > 37.2) {
            info[row][6] = "否";
        }
        else {
            info[row][6] = "是";
        }
        updatexml();
        qInfo() << "row:" << row;

        if (temp <= 37.2 && temp >= 34)
        {
            return 1;
        }
        else if (temp > 37.2 && temp <= 42) {
            return 2;
        }

    }
    else {

        if (_age > 200 || _age < 0) {
            return 3;
        }
        else if (_temp > 42 || _temp < 34) {
            return 4;
        }
        else if (_phone.length() != 11) {
            return 5;
        }
        else if (_id.length() != 18) {
            return 6;
        }
        m_mainWindow->insertrow(_name, _age, _phone, _id, _address, _temp);
        name = _name;
        age = _age;
        phone = _phone;
        id = _id;
        address = _address;
        temp = _temp;
        foo.clear();
        foo.push_back(_name);
        foo.push_back(QString::number(_age));
        foo.push_back(_phone);
        foo.push_back(_id);
        foo.push_back(_address);
        foo.push_back(QString::number(_temp));
        if (_temp > 37.2) {
            foo.push_back("否");
        }
        else {
            foo.push_back("是");
        }
        info.push_back(foo);
        for (auto vec : info) {
            for (auto str : vec) {
                qInfo() << str;
            }
        }
        addXML();
        if (_temp <= 37.2 && _temp >= 34)
        {
            return 1;
        }
        else if (_temp > 37.2 && _temp <= 42) {
            return 2;
        }
    }
}

void dbustrans::updatelabel(int _row, int _column) {
//    qInfo() << "update";
    if (QGSettings::isSchemaInstalled("org.healthy")) {
       m_gsettings = new QGSettings("org.healthy");
    }
    m_gsettings->set("name", info[_row][0]);
    m_gsettings->set("age", info[_row][1]);
    m_gsettings->set("phone", info[_row][2]);
    m_gsettings->set("id", info[_row][3]);
    m_gsettings->set("address", info[_row][4]);
    m_gsettings->set("temp", info[_row][5]);
    m_mainWindow->getgsetting(m_gsettings->get("name").toString(), m_gsettings->get("age").toInt(), m_gsettings->get("phone").toString(), m_gsettings->get("id").toString(), m_gsettings->get("address").toString(), m_gsettings->get("temp").toDouble());
}

void dbustrans::addXML()
{
    //打开文件
        QFile file("test.xml");
        if(!file.open(QFile::ReadOnly))
            return;

        //增加一个一级子节点以及元素
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();

        QDomElement root=doc.documentElement();
        QDomElement people=doc.createElement("people");
        QDomElement name=doc.createElement("name");
        QDomText text;
        text=doc.createTextNode(info[info.size() - 1][0]);
        name.appendChild(text);
        people.appendChild(name);

//        if (QGSettings::isSchemaInstalled("org.healthy")) {
//           m_gsettings = new QGSettings("org.healthy");
//        }

        QDomElement age=doc.createElement("age");
        text=doc.createTextNode(info[info.size() - 1][1]);
        age.appendChild(text);
        people.appendChild(age);

        QDomElement phone=doc.createElement("phone");
        text=doc.createTextNode(info[info.size() - 1][2]);
        phone.appendChild(text);
        people.appendChild(phone);

        QDomElement id=doc.createElement("id");
        text=doc.createTextNode(info[info.size() - 1][3]);
        id.appendChild(text);
        people.appendChild(id);

        QDomElement address=doc.createElement("address");
        text=doc.createTextNode(info[info.size() - 1][4]);
        address.appendChild(text);
        people.appendChild(address);

        QDomElement temp=doc.createElement("temp");
        text=doc.createTextNode(info[info.size() - 1][5]);
        temp.appendChild(text);
        people.appendChild(temp);

        QDomElement pass=doc.createElement("pass");
        if (QString(info[info.size() - 1][5]).toDouble() > 37.2) {
            text=doc.createTextNode("否");
        }
        else {
            text=doc.createTextNode("是");
        }
        pass.appendChild(text);
        people.appendChild(pass);

        root.appendChild(people);

        if(!file.open(QFile::WriteOnly|QFile::Truncate))
            return;
        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //缩进4格
        file.close();
}

void dbustrans::readxml() {
    //打开或创建文件
        QFile file("test.xml");
        if(!file.open(QFile::ReadOnly))
            return;

        QDomDocument doc;
        //设置test.xml到文档
        if(!doc.setContent(&file))
        {
            file.close();
//            qInfo() << "debug";
            return;
        }
        file.close();

        //返回根节点
        QDomElement root=doc.documentElement();
        //获得第一个子节点
        QDomNode node=root.firstChild();
        while(!node.isNull())  //如果节点不空
        {
            if(node.isElement()) //如果节点是元素
            {
                //转换为元素
                QDomElement e=node.toElement();
//                qInfo()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time");
                QDomNodeList list=e.childNodes();
//                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
//                m_mainWindow->restoretable();
                for(int i=0;i<list.count();i++)
                {
                    QDomNode n=list.at(i);
                    if(node.isElement())
//                    qInfo()<<n.nodeName()<<":"<<n.toElement().text();
                    foo.push_back(n.toElement().text());
                    m_mainWindow->restoretable(n, i);
                }
                info.push_back(foo);
                foo.clear();
            }
            //下一个兄弟节点
            node=node.nextSibling();
        }
}

void dbustrans::initxml() {
    //打开或创建文件
        QFile file("test.xml");
        //QIODevice::Truncate表示清空原来的内容
        if(!file.open(QFile::WriteOnly|QFile::Truncate))
            return;

        QDomDocument doc;
        //添加处理命令
        QDomProcessingInstruction instruction;
        instruction=doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
        doc.appendChild(instruction);
        //添加根节点
        QDomElement root=doc.createElement("info");
        doc.appendChild(root);

        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //缩进4格
        file.close();
}

void dbustrans::updatexml() {
    //打开文件
        QFile file("test.xml");
        if(!file.open(QFile::ReadOnly))
            return;

        //更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
        //或者用遍历的方法去匹配tagname或者attribut，value来更新
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();

        QDomElement root=doc.documentElement();
        QDomNodeList list=root.elementsByTagName("people");
//        for (int i = 0; i < list.count(); i++) {
//            QDomNodeList child = list.at(i).childNodes();
//            child.at(0)
//        }

//        QDomNode node=list.at(row); //定位到第三个一级子节点的子元素
//        node.setNodeValue("34");
        QDomNodeList no = list.at(row).childNodes();
        no.at(0).toElement().firstChild().setNodeValue(QString(info[row][0]));
        no.at(1).toElement().firstChild().setNodeValue(QString(info[row][1]));
        no.at(2).toElement().firstChild().setNodeValue(QString(info[row][2]));
        no.at(3).toElement().firstChild().setNodeValue(QString(info[row][3]));
        no.at(4).toElement().firstChild().setNodeValue(QString(info[row][4]));
        no.at(5).toElement().firstChild().setNodeValue(QString(info[row][5]));

            no.at(6).toElement().firstChild().setNodeValue(QString(info[row][6]));

        if(!file.open(QFile::WriteOnly|QFile::Truncate))
            return;
        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //缩进4格
        file.close();
}

QString dbustrans::getname() {
    return name;
}

int dbustrans::getage() {
    return age;
}

QString dbustrans::getphone() {
    return phone;
}

QString dbustrans::getid() {
    return id;
}

QString dbustrans::getaddress() {
    return address;
}

double dbustrans::gettemp() {
    return temp;
}
