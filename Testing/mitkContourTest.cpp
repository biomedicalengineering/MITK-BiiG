#include "mitkContour.h"
#include "mitkCommon.h"

#include <fstream>
int mitkContourTest(int argc, char* argv[])
{
  mitk::Contour::Pointer contour;
  std::cout << "Testing mitk::Contour::New(): ";
  contour = mitk::Contour::New();
  if (contour.IsNull()) {
    std::cout<<"[FAILED]"<<std::endl;
    return EXIT_FAILURE;
  }
  else {
  std::cout<<"[PASSED]"<<std::endl;
  } 

  std::cout << "Testing mitk::Contour::AddVertex(): ";
  mitk::ITKPoint3D p;
  p.Fill(0);
  contour->AddVertex(p);
  p.Fill(1);
  contour->AddVertex(p);
  p.Fill(2);
  contour->AddVertex(p);
  
  if (contour->GetNumberOfPoints() != 3)   
    {
      std::cout<<"[FAILED]"<<std::endl;
      return EXIT_FAILURE;
    }
  else 
    {
    std::cout<<"[PASSED]"<<std::endl;
    } 


  std::cout << "Testing mitk::Contour::GetPoints()";
  mitk::Contour::PointsContainerPointer points = contour->GetPoints();
  if ( points.IsNull() )   
    {
      std::cout<<"[FAILED]"<<std::endl;
      return EXIT_FAILURE;
    }
  else 
    {
    std::cout<<"[PASSED]"<<std::endl;
    } 

  std::cout << "Testing mitk::Contour::Initialize()";
  contour->Initialize();
  if (contour->GetNumberOfPoints() != 0)   
    {
      std::cout<<"[FAILED]"<<std::endl;
      return EXIT_FAILURE;
    }
  else 
    {
    std::cout<<"[PASSED]"<<std::endl;
    } 

  contour->SetPoints(points);
  if ( contour->GetNumberOfPoints() != 3)
    {
      std::cout<<"[FAILED]"<<std::endl;
      return EXIT_FAILURE;      
    };
  

  std::cout<<"[TEST DONE]"<<std::endl;
  return EXIT_SUCCESS;
}
