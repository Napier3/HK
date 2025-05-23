#ifndef STATEMONITORPLOT_H
#define STATEMONITORPLOT_H

#include <qwt_plot.h>
#include <qwt_interval.h>
#include <qwt_system_clock.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_picker.h>
#include <qwt_math.h>
#include <qwt_scale_engine.h>
#include <qwt_symbol.h>
#include <qwt_plot_grid.h>
#include <qwt_legend.h>
#include <qwt_text.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_canvas.h>
#include <qwt_painter.h>
#include <qwt_plot_layout.h>
#include <qwt_point_data.h>
#include <qwt_system_clock.h>
#include <qwt_plot_directpainter.h>
#include <qwt_curve_fitter.h>
#include <qwt_picker_machine.h>
#include <qwt_scale_widget.h>
#include <qregexp.h>
#include <qapplication.h>

#include "../SttUIDefine.h"
#include "../../Module/SttTest/Common/tmt_common_def.h"
#include "../../Module/SttTest/Common/tmt_result_def.h"

class QwtPlotCurve;
class QwtPlotMarker;
class QwtPlotDirectPainter;

class QwtPlotZoomer;
class QwtPlotPicker;
class QwtPlotPanner;

#define  SPACE		0.5
#define  TIMER		1000

#define MAX_BIN_CNT	10
#define MAX_BIN_EX_CNT	128
#define MAX_COLOR_NUM	16

#define STATE_UPDATE_FREE		0x00
#define STATE_UPDATE_TIMER		0x01
#define STATE_UPDATE_CHANGE		0x02

extern QColor g_arrColor[MAX_COLOR_NUM];
extern QString GetCurveStyleSheet(long nColorIndex);

//自画坐标轴,以字符方式显示所有的通道
class BinBoutYScaleDraw: public QwtScaleDraw        
{
public:
	BinBoutYScaleDraw()
	{
	}
	virtual QwtText label( double v ) const  //重绘坐标轴 刻度值
	{
		if(v <= g_nBinCount)
		{
			return QwtText(QString("   %1").arg(QChar('A' - 1 + (int)v)));
		}
		else if(v <= 20)
		{
			return QwtText(QString("   %1").arg((int)v - g_nBinCount));		
		}
		else
		{
			return QwtText(" ");
		}
	}
};

class UIYScaleDraw: public QwtScaleDraw        //自画坐标轴
{
public:
	UIYScaleDraw()
	{
	}
	virtual QwtText label( double v ) const  //重绘坐标轴 刻度值
	{
		return QwtText(QString::number( v) );
	}
};

class CurveData: public QwtArraySeriesData<QPointF>
{
public:
	CurveData()
	{
		miny = 0;
		maxy = 1;
		minx = 0;
		maxx = 1;
		d_samples.reserve(6000);
	}

	virtual QRectF boundingRect() const
	{
		if ( d_boundingRect.width() < 0.0 )
			d_boundingRect = qwtBoundingRect( *this );

		return d_boundingRect;
	}

	void append( const QPointF &point );

	void clear()
	{
		d_samples.clear();
		d_samples.squeeze();
		d_boundingRect = QRectF( 0.0, 0.0, -1.0, -1.0 );
	}

	void setPoint(long nIndex, double x, double y)
	{
		if(nIndex < d_samples.size())
		{
			d_samples[nIndex].setX(x);
			d_samples[nIndex].setY(y);
		}
	}

	size_t size(){
	    return d_samples.size();
	}

public:
	double miny;
	double maxy;
	double minx;
	double maxx;

};

class QStateMonitorData : public CExBaseList
{
public:
	QPointF m_oPoint;

	QStateMonitorData() {}
	virtual ~QStateMonitorData() {}
};

class QStateMonitorPlot : public QwtPlot
{
Q_OBJECT
public:
	double m_dRealTime;//测试启动的绝对时间
	double m_dLastTime;//测试启动的相对时间
	QList<QVector<QPointF> > m_oPreUpdateList;//准备更新的曲线数据链表
	QList<QVector<QPointF> > m_oUpdateList;//需要更新的曲线数据链表
	QList<QwtPlotCurve*> m_oCurveList;//曲线链表

public:
	QStateMonitorPlot(QWidget* parent = 0);
	virtual ~QStateMonitorPlot();
	virtual void InitUI();

	virtual void UpdateYTtile(QString strTitle, long nFontSize=9,bool bLeft = true);
	virtual void UpdateYScale(float f1, float f2, bool bLeft = true);
	virtual void UpdateXTtile(QString strTitle);
	virtual void UpdateXScale(float f1, float f2);
	virtual void UpdateYLeftRightScale(changed_type tagType, float fDown, float fUp);

	virtual void UpdateCurves();
	virtual void SetInit(bool bInit) { m_bNeedInit = bInit; };
	virtual void ClearCurves();
	virtual void AddStopPoint();//添加绘图中止点

protected:
	QwtInterval m_oXinterval;//x轴范围
	QwtInterval m_oYinterval;//y轴范围
	QwtPlotPicker* m_pCursorPicker;//坐标指示器
	QwtPlotGrid* m_pGrid;
	QwtScaleWidget *m_pScaleWidget;
	bool m_bNeedInit;
	CExBaseList* m_pLastPoints;
	QwtPlotDirectPainter m_oPainter;//增量绘图工具

protected:
	void InitGrid(); //初始化网格背景
	virtual void UpdateCurve(long nIndex, const QVector<QPointF>& points);//更新每个QwtPlotCurve
};

#endif // STATEMONITORPLOT_H
