#include "deneme_2.h"
#include <vtkCubeSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkTriangle.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAlgorithm.h>

// Gerekli render modüllerini otomatik başlatmak için VTK AutoInit
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);  // OpenGL2 Rendering başlatılır
VTK_MODULE_INIT(vtkInteractionStyle); // Etkileşim stilleri başlatılır

VTK_MODULE_INIT(vtkRenderingFreeType);

int main() {
    // vtkPolyData nesnesi oluşturulur.
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();

    // Noktalar tanımlanır.
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0.0, 0.0, 0.0);
    points->InsertNextPoint(1.0, 0.0, 0.0);
    points->InsertNextPoint(0.5, 1.0, 0.0);

    // Üçgen hücre tanımlanır ve noktalara bağlanır.
    vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
    triangle->GetPointIds()->SetId(0, 0);
    triangle->GetPointIds()->SetId(1, 1);
    triangle->GetPointIds()->SetId(2, 2);

    vtkSmartPointer<vtkCellArray> triangles = vtkSmartPointer<vtkCellArray>::New();
    triangles->InsertNextCell(triangle);

    // vtkPolyData'ya noktalar ve hücreler eklenir.
    polyData->SetPoints(points);
    polyData->SetPolys(triangles);

    // Görselleştirme için mapper ve actor ayarlanır.
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polyData);

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // Render ayarları yapılır.
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
    renderer->SetBackground(0.1, 0.2, 0.4); // Arka plan rengi

    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    // Render işlemi başlatılır.
    renderWindow->Render();
    renderWindowInteractor->Start();

    return 0;
}
