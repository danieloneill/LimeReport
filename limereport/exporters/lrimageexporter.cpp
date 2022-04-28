#include "lrimageexporter.h"
#include "lrexportersfactory.h"
#include "lrreportengine_p.h"

namespace{

LimeReport::ReportExporterInterface* createImageExporter(LimeReport::ReportEnginePrivate* parent){
    return new LimeReport::ImageExporter(parent);
}

bool VARIABLE_IS_NOT_USED registered = LimeReport::ExportersFactory::instance().registerCreator("Image", LimeReport::ExporterAttribs(QObject::tr("Export to Image"), "ImageExporter"), createImageExporter);

}

namespace LimeReport{

ImageExporter::ImageExporter(ReportEnginePrivate *parent) : QObject(parent), m_reportEngine(parent)
{}

bool ImageExporter::exportPages(ReportPages pages, const QString &fileName, const QMap<QString, QVariant> &params)
{
    Q_UNUSED(fileName)

    int resolution = 600;
    QImage image;

    if( params.contains("resolution") )
        resolution = params["resolution"].toInt();

    if (!pages.isEmpty()){
        m_reportEngine->exportPagesToImage(pages, &image, resolution);
        m_reportEngine->emitExportedToImage();
        return true;
    }
    return false;
}

}
