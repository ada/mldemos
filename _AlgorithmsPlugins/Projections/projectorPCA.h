#ifndef PCAPROJECTION_H
#define PCAPROJECTION_H

#include <public.h>
#include <mymaths.h>
#include <projector.h>
#include <QLabel>
#define OPENCV22
#include "basicOpenCV.h"

using namespace std;
using namespace cv;

class ProjectorPCA : public Projector
{
    PCA pca;
    PCA compressPCA(const Mat& pcaset, int maxComponents, const Mat& testset, Mat& compressed);
    void TrainPCA(std::vector<fvec> samples, int count=2);
public:
    ProjectorPCA();
    void DrawEigenvals(QPainter &painter);
    fvec GetEigenValues();

    void Train(std::vector< fvec > samples, ivec labels);
    fvec Project(const fvec &sample);
    char *GetInfoString(){return "Principal Component Analysis";}

};

#endif // PCAPROJECTION_H
