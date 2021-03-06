#include<iostream>
#include<fstream>

#include"polyhedron.h"
#include"triangulate.h"

void extrusion_test(){
	std::vector<double> coords;
	std::vector<int>    contour;
	
	coords.push_back( -2.0 ); coords.push_back(  0.05 );
	coords.push_back( -2.0 ); coords.push_back(  1.0 );
	coords.push_back( -1.0 ); coords.push_back(  1.0 );
	coords.push_back(  0.0 ); coords.push_back(  0.1 );
	coords.push_back(  1.0 ); coords.push_back(  1.0 );
	coords.push_back(  1.0 ); coords.push_back(  0.05 );
	contour.push_back( 0 );
	contour.push_back( 1 );
	contour.push_back( 2 );
	contour.push_back( 3 );
	contour.push_back( 4 );
	contour.push_back( 5 );
	
	polyhedron P;
	P.initialize_create_surface_of_revolution( coords, contour, 270.0, 100 );
	P.output_store_in_file( "SOR.obj" );
}

void triangulate_test(){
	std::vector<double> coords;
	std::vector<int> faces, tris;
	coords.push_back( -1.0 ); coords.push_back( -1.0 ); coords.push_back( 0.0 );
	coords.push_back(  1.0 ); coords.push_back( -1.0 ); coords.push_back( 0.0 );
	coords.push_back(  1.0 ); coords.push_back(  0.0 ); coords.push_back( 0.0 );
	coords.push_back(  0.1 ); coords.push_back(  0.0 ); coords.push_back( 0.0 );
	coords.push_back(  1.0 ); coords.push_back(  1.0 ); coords.push_back( 0.0 );
	coords.push_back( -1.0 ); coords.push_back(  1.0 ); coords.push_back( 0.0 );
	
	faces.push_back( 7 );
	faces.push_back( 0 );
	faces.push_back( 1 );
	faces.push_back( 2 );
	faces.push_back( 3 );
	faces.push_back( 2 );
	faces.push_back( 4 );
	faces.push_back( 5 );
	
	triangulate_simple_polygon( coords, &faces[0], tris );
	
	polyhedron p;
	p.initialize_load_from_mesh( coords, tris );
	p.output_store_in_file( "triangulate_test_a.obj" );
}

int main( int argc, char **argv ){
	//triangulate_test();
	//return 0;
	/*
	extrusion_test();
	*/
	polyhedron A, B, C;
	A.initialize_create_cylinder( 1.0, 2.0, true );
	A.output_store_in_file( "cylinder.obj" );
	
	A.initialize_create_box( 6.0, 6.0, 6.0, true );
	B.initialize_create_sphere( 3.01, true );
	
	B.output_store_in_file("tmp.obj");
	
	C = A-B;
    C.triangulate().output_store_in_file("dump.obj");
	
	//C.triangulate().output_store_in_file("dump.vtp");
	
	
	//polyhedron C = box( 1.0, 1.0, 1.0, true );
	//C.triangulate().output_store_in_file("dump.obj");
	 
	return 0;
}