//
//  VectorFont.h
//  FontTest
//
//  Created by Seb Lee-Delisle on 21/08/2012.
//
//

#pragma once 
#include "Letter.h"

class VectorFont {
	
	
	public:
	
	VectorFont () {
		
		Letter A;
		A.addLine(0, 0, 4, 0);
		A.addLine(0, 0, 0, 6);
		A.addLine(4, 0, 4, 6);
		A.addLine(0, 3, 4, 3);
		
		letters['A'] = A;
		
		Letter B;
		B.addLine(0, 0, 4, 0);
		B.addLine(0, 0, 0, 6);
		B.addLine(4, 0, 4, 6);
		B.addLine(0, 3, 4, 3);
		B.addLine(0, 6, 4, 6);
		
		letters['B'] = B;
		
	}
	
	
	map <int, Letter> letters;
	
	
};