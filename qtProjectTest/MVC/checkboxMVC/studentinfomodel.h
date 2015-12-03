/*      网址：http://qimo601.iteye.com/blog/1530232
 *第二种方法：设置QAbstractTableModel的flags()函数法
        通过Delegate创建QCheckBox来实现的Check列，只有在该列进入编辑模式时才能够Check/Uncheck。
这显然不是我们想要的，网上翻来翻去，在一个国外论坛中看到了无需Delegate的实现方法，只需重写Model即可：

主要是修改两个函数：
//设置某一列为可选角色，绘画出QCheckBox
Qt::ItemFlags flags(const QModelIndex &index) const;
//根据界面选择QCheckbox，修改Model中的数据
 bool setData(const QModelIndex &index, const QVariant &value, int role);

 **/

#ifndef STUDENTINFOMODEL_H
#define STUDENTINFOMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include <QVector>
class StudentInfo
{
public:
    StudentInfo(){}
    StudentInfo(QString stuNumber1,QString stuName1, QString stuID1,\
                QString stuPhoneNumber1,QString department1, QString stuDescription1)
    {
        stuNumber=stuNumber1;
        stuName=stuName1;
        stuID=stuID1;
        stuPhoneNumber=stuPhoneNumber1;
        department=department1;
        stuDescription=stuDescription1;

    }
//    StudentInfo(StudentInfo &stuInfo)
//    {
//        stuNumber=stuInfo.stuNumber;
//        stuName=stuInfo.stuName;
//        stuID=stuInfo.stuID;
//        stuPhoneNumber=stuInfo.stuPhoneNumber;
//        department=stuInfo.department;
//        stuDescription=stuInfo.stuDescription;
//    }
    StudentInfo(const StudentInfo &stuInfo)
    {
        stuNumber=stuInfo.stuNumber;
        stuName=stuInfo.stuName;
        stuID=stuInfo.stuID;
        stuPhoneNumber=stuInfo.stuPhoneNumber;
        department=stuInfo.department;
        stuDescription=stuInfo.stuDescription;
    }




    QString stuNumber;
    QString stuName;
    QString stuID;
    QString stuPhoneNumber;
    QString department;
    QString stuDescription;

};

class StudentInfoModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    StudentInfoModel(const int totalColumn, const int aColumnNumWithChechBox = 0, QObject *parent = 0) \
        :totalColumn(totalColumn),colNumberWithCheckBox(aColumnNumWithChechBox),\
          QAbstractTableModel(parent) {rowCheckStateMap.clear();};
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

   //void insertRows(int row, int count, const QModelIndex &parent);
public:
    void AddStudentInfo( StudentInfo  studentInfo);


signals:
    void StudentInfoIsChecked(const StudentInfo &studentInfo);


private:
    typedef QVector<StudentInfo> StudentInfos;
    StudentInfos studentInfos;
    int totalColumn;
    int colNumberWithCheckBox;
    QMap<int, Qt::CheckState> rowCheckStateMap;
};

#endif // STUDENTINFOMODEL_H
