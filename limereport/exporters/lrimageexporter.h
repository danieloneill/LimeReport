#ifndef LRIMAGEEXPORTER_H
#define LRIMAGEEXPORTER_H

#include <QObject>
#include "lrexporterintf.h"

namespace LimeReport{
class ReportEnginePrivate;

class ImageExporter : public QObject, public ReportExporterInterface
{
    Q_OBJECT
public:
    explicit ImageExporter(ReportEnginePrivate *parent = NULL);
    // ReportExporterInterface interface
    bool exportPages(ReportPages pages, const QString &fileName, const QMap<QString, QVariant> &params);
    QString exporterName()
    {
        return "Image";
    }
    QString exporterFileExt()
    {
        return "png";
    }
    QString hint()
    {
        return tr("Export to Image");
    }
private:
    ReportEnginePrivate* m_reportEngine;
};

} //namespace LimeReport

#endif // LRIMAGEEXPORTER_H
