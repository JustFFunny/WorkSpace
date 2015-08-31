#include "MyLabel.h"


MyQLabel::MyQLabel(QWidget *parent)
	:	QLabel(parent)
{
	InitVar();
}

MyQLabel::~MyQLabel()
{
	if (m_timer)
	{
		if (m_timer->isActive())
		{
			m_timer->stop();
		}
		delete m_timer;
	}
}

void MyQLabel::InitVar(int mscond)
{
	m_timer = NULL;
	m_msecond = mscond;
	m_context = "";
	m_pos = 0;
	m_rool = ROOL_1;//默认滚动方式
}

void MyQLabel::SetText(const QString &context, const int &mscond)
{
	bool b=false;

	m_context = context;
	m_msecond = mscond;

	if (0 != m_msecond)
	{
		if (NULL == m_timer)
		{
			m_timer = new QTimer(this);

			if (m_timer)
			{
				b = connect(m_timer, SIGNAL(timeout()), this, SLOT(SlotTimeOut()));
				m_timer->start(m_msecond);
			}
		}
	}
}

void MyQLabel::SlotTimeOut()
{
	QString str="";

	if (m_pos > m_context.count())
	{
		m_pos = 0;
	}

	switch (m_rool)
	{
		case ROOL_0://滚动方式1
			str = m_context.mid(m_pos);
			break;
		case ROOL_1://滚动方式2
			setAlignment(Qt::AlignRight);
			str = m_context.mid(0, m_pos);
			break;
	}

	setText(str);
	m_pos++;
}
