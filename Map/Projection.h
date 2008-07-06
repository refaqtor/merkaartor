#ifndef MERKATOR_PROJECTION_H_
#define MERKATOR_PROJECTION_H_

#include "Preferences/MerkaartorPreferences.h"
#include "Map/Coord.h"

#include <QtCore/QPointF>

class QRect;
class LayerManager;

class Projection
{
	public:
		Projection(void);
		virtual ~Projection(void) {};

		void setViewport(const CoordBox& Map, const QRect& Screen);
		void panScreen(const QPoint& p, const QRect& Screen);
		CoordBox viewport() const;
		QPointF project(const Coord& Map) const;
		double pixelPerM() const;
		double latAnglePerM() const;
		double lonAnglePerM(double Lat) const;
		Coord inverse(const QPointF& Screen) const;
		void zoom(double d, const QPointF& Around, const QRect& Screen);
		void setCenter(Coord& Center, const QRect& Screen);

		void setLayerManager(LayerManager* lm);

		virtual bool toXML(QDomElement xParent) const;
		void fromXML(QDomElement e, const QRect & Screen);

		void setProjectionType(ProjectionType aProjectionType);

	protected:
		double ScaleLat, DeltaLat, ScaleLon, DeltaLon;
		CoordBox Viewport;
		QPoint screen_middle;
		LayerManager* layermanager;
		ProjectionType theProjectionType;

	private:
		void viewportRecalc(const QRect& Screen);
		void layerManagerSetViewport(const CoordBox& Map, const QRect& Screen);
		void layerManagerViewportRecalc(const QRect& Screen);
		QPointF screenToCoordinate(QPointF click) const;
		QPoint coordinateToScreen(QPointF click) const;
};

#endif


