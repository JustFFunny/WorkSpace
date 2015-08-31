#ifndef __MYLABEL_H__
#define __MYLABEL_H__

#include <QLabel>
#include <QTimer>




#define ROOL_0			0//显示滚动方式1
#define ROOL_1			1//显示滚动方式2


class MyQLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyQLabel(QWidget *parent=0);
	~MyQLabel();

	/*
	 * 设置文本:
	 * 1. 如果mscond为0则文字不滚动(默认不滚动);
	 * 2. 如果调用setText()文字将不滚动(与使用QLabel相同);
	*/
	void SetText(const QString &context=0, const int &mscond=0);

private slots:
	void SlotTimeOut();

private:
	QTimer *m_timer;
	int m_msecond;
	QString m_context;
	int m_pos;
	int m_rool;

private:
	void InitVar(int mscond=0);
};

#endif