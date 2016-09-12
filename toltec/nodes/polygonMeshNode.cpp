/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "polygonMeshNode.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

//#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>

#include "toltecPolygonMeshLibrary/mesh.hpp"

/*-----------------------------------------------------------------------------
*	TYPEDEFS
*-----------------------------------------------------------------------------*/
//typedef OpenMesh::PolyMesh_ArrayKernelT<> PolyMesh;

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
PolygonMeshNode::PolygonMeshNode()
{
	//PolyMesh mesh;

	////CREATE VERTICES
	//PolyMesh::VertexHandle vertexHandles[8];

	//vertexHandles[0] = mesh.add_vertex(PolyMesh::Point(-1, -1,  1));
	//vertexHandles[1] = mesh.add_vertex(PolyMesh::Point( 1, -1,  1));
	//vertexHandles[2] = mesh.add_vertex(PolyMesh::Point( 1,  1,  1));
	//vertexHandles[3] = mesh.add_vertex(PolyMesh::Point(-1,  1,  1));
	//vertexHandles[4] = mesh.add_vertex(PolyMesh::Point(-1, -1, -1));
	//vertexHandles[5] = mesh.add_vertex(PolyMesh::Point( 1, -1, -1));
	//vertexHandles[6] = mesh.add_vertex(PolyMesh::Point( 1,  1, -1));
	//vertexHandles[7] = mesh.add_vertex(PolyMesh::Point(-1,  1, -1));

	////CREATE FACES
	////The orientation of the face is defined by the order in which the vertices are 
	////given: If you look at the frontfacing side of the polygon, then the vertices 
	////are in counter-clockwise order.
	//std::vector<PolyMesh::VertexHandle> faceBuildList;
	//
	////face0
	//faceBuildList.clear();
	//faceBuildList.push_back(vertexHandles[0]);
	//faceBuildList.push_back(vertexHandles[1]);
	//faceBuildList.push_back(vertexHandles[2]);
	//faceBuildList.push_back(vertexHandles[3]);
	//mesh.add_face(faceBuildList);

	////face1
	//faceBuildList.clear();
	//faceBuildList.push_back(vertexHandles[7]);
	//faceBuildList.push_back(vertexHandles[6]);
	//faceBuildList.push_back(vertexHandles[5]);
	//faceBuildList.push_back(vertexHandles[4]);
	//mesh.add_face(faceBuildList);

	////face2
	//faceBuildList.clear();
	//faceBuildList.push_back(vertexHandles[1]);
	//faceBuildList.push_back(vertexHandles[0]);
	//faceBuildList.push_back(vertexHandles[4]);
	//faceBuildList.push_back(vertexHandles[5]);
	//mesh.add_face(faceBuildList);

	////face3
	//faceBuildList.clear();
	//faceBuildList.push_back(vertexHandles[2]);
	//faceBuildList.push_back(vertexHandles[1]);
	//faceBuildList.push_back(vertexHandles[5]);
	//faceBuildList.push_back(vertexHandles[6]);
	//mesh.add_face(faceBuildList);

	////face4
	//faceBuildList.clear();
	//faceBuildList.push_back(vertexHandles[3]);
	//faceBuildList.push_back(vertexHandles[2]);
	//faceBuildList.push_back(vertexHandles[6]);
	//faceBuildList.push_back(vertexHandles[7]);
	//mesh.add_face(faceBuildList);

	////face5
	//faceBuildList.clear();
	//faceBuildList.push_back(vertexHandles[0]);
	//faceBuildList.push_back(vertexHandles[3]);
	//faceBuildList.push_back(vertexHandles[7]);
	//faceBuildList.push_back(vertexHandles[4]);
	//mesh.add_face(faceBuildList);

	////DISPLAY INFO
	//std::cout << "Polygons\n";
	//for (PolyMesh::FaceIter faceIter = mesh.faces_begin(); faceIter != mesh.faces_end(); faceIter++)
	//{
	//	std::cout << "Face" << faceIter->idx() << std::endl;
	//	for (
	//		PolyMesh::FaceVertexIter faceVertexIter = mesh.fv_iter(*faceIter);
	//		faceVertexIter.is_valid();
	//		faceVertexIter++)
	//	{
	//		PolyMesh::Point point = mesh.point(*faceVertexIter);
	//		std::cout
	//			<< faceVertexIter->idx() << " :  "
	//			<< "x: " << std::setw(4) << point[0] << " | "
	//			<< "y: " << std::setw(4) << point[1] << " | "
	//			<< "z: " << std::setw(4) << point[2]
	//			<< std::endl;
	//	}
	//}

	////TRIANGULATION I
	//std::cout << "\nTriangles 1\n";
	//mesh.triangulate();
	//for (auto face : mesh.faces())
	//{
	//	std::cout << "Face" << face.idx() << std::endl;
	//	for (auto faceVertex : mesh.fv_range(face))
	//	{
	//		PolyMesh::Point point = mesh.point(faceVertex);
	//		std::cout
	//			<< faceVertex.idx() << " :  "
	//			<< "x: " << std::setw(4) << point[0] << " | "
	//			<< "y: " << std::setw(4) << point[1] << " | "
	//			<< "z: " << std::setw(4) << point[2]
	//			<< std::endl;
	//	}
	//}

	////TRIANGULATION II
	//std::cout << "\nTriangles 2\n";
	//for (PolyMesh::FaceHandle face : mesh.faces())
	//{
	//	std::cout << "Face" << face.idx() << std::endl;
	//	mesh.triangulate(face);
	//	for (PolyMesh::VertexHandle faceVertex : mesh.fv_range(face))
	//	{
	//		PolyMesh::Point point = mesh.point(faceVertex);
	//		std::cout
	//			<< faceVertex.idx() << " :  "
	//			<< "x: " << std::setw(4) << point[0] << " | "
	//			<< "y: " << std::setw(4) << point[1] << " | "
	//			<< "z: " << std::setw(4) << point[2]
	//			<< std::endl;
	//	}
	//}

	/*----------------------------------------------------------------------------*/

	tpm::Mesh polyMesh;

	//CREATE VERTICES
	std::vector<tpm::Vertex*> vertexList;

	vertexList.push_back(polyMesh.addVertex(-1, -1,  1));
	vertexList.push_back(polyMesh.addVertex( 1, -1,  1));
	vertexList.push_back(polyMesh.addVertex( 1,  1,  1));
	vertexList.push_back(polyMesh.addVertex(-1,  1,  1));
	vertexList.push_back(polyMesh.addVertex(-1, -1, -1));
	vertexList.push_back(polyMesh.addVertex( 1, -1, -1));
	vertexList.push_back(polyMesh.addVertex( 1,  1, -1));
	vertexList.push_back(polyMesh.addVertex(-1,  1, -1));

	//CREATE FACES
	std::vector<tpm::Vertex*> faceBuildList;

	//face0
	faceBuildList.clear();
	faceBuildList.push_back(vertexList[0]);
	faceBuildList.push_back(vertexList[1]);
	faceBuildList.push_back(vertexList[2]);
	faceBuildList.push_back(vertexList[3]);
	polyMesh.addFace(faceBuildList);

	//face1
	faceBuildList.clear();
	faceBuildList.push_back(vertexList[7]);
	faceBuildList.push_back(vertexList[6]);
	faceBuildList.push_back(vertexList[5]);
	faceBuildList.push_back(vertexList[4]);
	polyMesh.addFace(faceBuildList);

	//face2
	faceBuildList.clear();
	faceBuildList.push_back(vertexList[1]);
	faceBuildList.push_back(vertexList[0]);
	faceBuildList.push_back(vertexList[4]);
	faceBuildList.push_back(vertexList[5]);
	polyMesh.addFace(faceBuildList);

	//face3
	faceBuildList.clear();
	faceBuildList.push_back(vertexList[2]);
	faceBuildList.push_back(vertexList[1]);
	faceBuildList.push_back(vertexList[5]);
	faceBuildList.push_back(vertexList[6]);
	polyMesh.addFace(faceBuildList);

	//face4
	faceBuildList.clear();
	faceBuildList.push_back(vertexList[3]);
	faceBuildList.push_back(vertexList[2]);
	faceBuildList.push_back(vertexList[6]);
	faceBuildList.push_back(vertexList[7]);
	polyMesh.addFace(faceBuildList);

	//face5
	faceBuildList.clear();
	faceBuildList.push_back(vertexList[0]);
	faceBuildList.push_back(vertexList[3]);
	faceBuildList.push_back(vertexList[7]);
	faceBuildList.push_back(vertexList[4]);
	polyMesh.addFace(faceBuildList);
}
