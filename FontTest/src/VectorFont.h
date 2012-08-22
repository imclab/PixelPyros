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
		A.addLine(0, 6, 0, 1);
		A.addLine(0, 1, 2, 0);
		A.addLine(2, 0, 4, 1);
		A.addLine(4, 1, 4, 6);
        A.addLine(0, 3, 4, 3);
		
		letters['A'] = A;
		
		Letter B;
		B.addLine(0, 6, 0, 0);
		B.addLine(0, 6, 0, 0);
		B.addLine(0, 0, 3, 0);
		B.addLine(3, 0, 4, 1);
		B.addLine(4, 1, 4, 2);
        B.addLine(4, 2, 3, 3);
        B.addLine(3, 3, 4, 4);
        B.addLine(4, 4, 4, 5);
        B.addLine(4, 5, 3, 6);
        B.addLine(3, 6, 0, 6);
        B.addLine(0, 6, 0, 3);
        B.addLine(0, 3, 3, 3);
		
		letters['B'] = B;
        
        Letter C;
		C.addLine(4, 0, 0, 0);
		C.addLine(0, 0, 0, 6);
		C.addLine(0, 6, 4, 6);
        
		letters['C'] = C;
		
        Letter D;
		D.addLine(0, 0, 0, 0);
		D.addLine(0, 0, 3, 0);
		D.addLine(3, 0, 4, 2);
        D.addLine(4, 2, 4, 4);
        D.addLine(4, 4, 3, 6);
        D.addLine(3, 6, 0, 6);
        D.addLine(0, 6, 0, 0);
        
		letters['D'] = D;
        
        Letter E;
		E.addLine(4, 0, 0, 0);
		E.addLine(0, 0, 0, 0);
        E.addLine(0, 0, 0, 6);
        E.addLine(0, 6, 4, 6);
        E.addLine(0, 3, 4, 3);
        
		letters['E'] = E;
        
        Letter F;
		F.addLine(4, 0, 0, 0);
		F.addLine(0, 0, 0, 0);
        F.addLine(0, 0, 0, 6);
        F.addLine(0, 6, 0, 3);
        F.addLine(0, 3, 4, 3);
        
		letters['F'] = F;
        
        Letter G;
        G.addLine(4, 0, 0, 0);
		G.addLine(0, 0, 0, 0);
        G.addLine(0, 0, 0, 6);
        G.addLine(0, 6, 4, 6);
        G.addLine(4, 6, 4, 3);
        G.addLine(4, 3, 2, 3);
        
        letters['G'] = G;
        
        Letter H;
        H.addLine(0, 0, 0, 6);
        H.addLine(4, 0, 4, 6);
        H.addLine(0, 3, 4, 3);
        
        letters['H'] = H;
        
        Letter I;
        I.addLine(0, 0, 4, 0);
        I.addLine(0, 6, 4, 6);
        I.addLine(2, 6, 2, 0);
        
        letters['I'] = I;
        
        Letter J;
        J.addLine(1, 0, 0, 0);
        J.addLine(0, 0, 4, 0);
        J.addLine(4, 0, 4, 4);
        J.addLine(4, 4, 3, 6);
        J.addLine(3, 6, 1, 6);
        J.addLine(1, 6, 0, 4);
        
        letters['J'] = J;
        
        Letter K;
        K.addLine(0, 0, 0, 6);
        K.addLine(4, 0, 0, 3);
        K.addLine(0, 3, 4, 6);
        
        letters['K'] = K;
        
        Letter L;
        L.addLine(0, 0, 0, 6);
        L.addLine(0, 6, 4, 6);
        
        letters['L'] = L;
        
        Letter M;
        M.addLine(0, 6, 0, 0);
        M.addLine(0, 0, 2, 2);
        M.addLine(2, 2, 4, 0);
        M.addLine(4, 0, 4, 6);
        
        letters['M'] = M;
        
        Letter N;
        N.addLine(0, 6, 0, 0);
        N.addLine(0, 1, 4, 5);
        N.addLine(4, 6, 4, 0);
        
        letters['N'] = N;
        
        Letter O;
        O.addLine(0, 0, 0, 0);
        O.addLine(0, 0, 4, 0);
        O.addLine(4, 0, 4, 6);
        O.addLine(4, 6, 0, 6);
        O.addLine(0, 6, 0, 0);
        
        letters['O'] = O;
        
        Letter P;
        P.addLine(0, 0, 0, 6);
        P.addLine(0, 6, 0, 0);
        P.addLine(0, 0, 4, 0);
        P.addLine(4, 0, 4, 3);
        P.addLine(4, 3, 0, 3);
        
        letters['P'] = P;
        
        Letter Q;
        Q.addLine(0, 0, 4, 0);
        Q.addLine(4, 0, 4, 4);
        Q.addLine(4, 4, 2, 6);
        Q.addLine(2, 6, 0, 6);
        Q.addLine(0, 6, 0, 0);
        Q.addLine(2, 4, 4, 6);
        
        letters['Q'] = Q;
        
        Letter R;
        R.addLine(0, 0, 0, 6);
        R.addLine(0, 6, 0, 0);
        R.addLine(0, 0, 4, 0);
        R.addLine(4, 0, 4, 3);
        R.addLine(4, 3, 0, 3);
        R.addLine(0, 3, 4, 6);
        
        letters['R'] = R;
        
        Letter S;
        S.addLine(4, 0, 0, 0);
        S.addLine(4, 0, 0, 0);
        S.addLine(0, 0, 0, 3);
        S.addLine(0, 3, 4, 3);
        S.addLine(4, 3, 4, 6);
        S.addLine(4, 6, 0, 6);
        
        letters['S'] = S;
        
        Letter T;
        T.addLine(0, 0, 4, 0);
        T.addLine(2, 0, 2, 6);
        
        letters['T'] = T;
        
        Letter U;
        U.addLine(0, 0, 0, 0);
        U.addLine(0, 0, 0, 5);
        U.addLine(0, 5, 1, 6);
        U.addLine(1, 6, 3, 6);
        U.addLine(3, 6, 4, 5);
        U.addLine(4, 5, 4, 0);
        
        letters['U'] = U;
        
        Letter V;
        V.addLine(0, 0, 0, 0);
        V.addLine(0, 0, 2, 6);
        V.addLine(2, 6, 4, 0);
        
        letters['V'] = V;
        
        Letter W;
        W.addLine(0, 0, 0, 0);
        W.addLine(0, 0, 0, 6);
        W.addLine(0, 6, 2, 4);
        W.addLine(2, 4, 4, 6);
        W.addLine(4, 6, 4, 0);
        
        letters['W'] = W;
        
        
        Letter X;
        X.addLine(0, 0, 4, 6);
        X.addLine(4, 0, 0, 6);
        
        letters['X'] = X;
        
        Letter Y;
        Y.addLine(0, 0, 2, 4);
        Y.addLine(2, 3, 4, 0);
        Y.addLine(2, 3, 2, 6);
        
        letters['Y'] = Y;
        
        Letter Z;
        Z.addLine(0, 0, 4, 0);
        Z.addLine(4, 0, 0, 6);
        Z.addLine(0, 6, 4, 6);
        
        letters['Z'] = Z;
        
        //        Letter 0;
        //        0.addLine(0, 0, 4, 0);
        //        0.addLine(4, 0, 4, 6);
        //        0.addLine(4, 6, 0, 6);
        //        0.addLine(0, 6, 0, 0);
        //        0.addLine(4, 0, 0, 6);
        //        
        //        letters['0'] = 0;
        //        
        //        Letter 1;
        //        1.addLine(2, 0, 2, 6);
        //      
        //        letters['1'] = 1;
        
        //        Letter 2;
        //        2.addLine(0, 0, 4, 0);
        //        2.addLine(4, 0, 4, 3);
        //        2.addLine(4, 3, 0, 3);
        //        2.addLine(0, 3, 0, 6);
        //        2.addLine(0, 6, 4, 6);
        //        
        //        letters['2'] = 2;
        //
        //        
        //        Letter 3;
        //        3.addLine(0, 0, 4, 0);
        //        3.addLine(4, 0, 4, 6);
        //        3.addLine(4, 6, 0, 6);
        //        3.addLine(0, 4, 4, 3);
        //        
        //        letters['3'] = 3;
        //        
        //        Letter 4;
        //        4.addLine(0, 0, 0, 3);
        //        4.addLine(0, 3, 4, 3);
        //        4.addLine(4, 3, 4, 6);
        //        4.addLine(4, 6, 0, 6);
        //        
        //        letters['4'] = 4;
        //        
        //        Letter 5;
        //        5.addLine(4, 0, 0, 0);
        //        5.addLine(0, 0, 0, 3);
        //        5.addLine(0, 3, 4, 3);
        //        5.addLine(4, 3, 4, 6);
        //        5.addLine(4, 6, 0, 6);
        //        
        //        letters['5'] = 5;
        //        
        //        Letter 6;
        //        6.addLine(0, 0, 0, 6);
        //        6.addLine(0, 6, 4, 6);
        //        6.addLine(4, 6, 4, 3);
        //        6.addLine(4, 3, 0, 3);
        //        
        //        letters['6'] = 6;
        //        
        //        
        //        Letter 7;
        //        7.addLine(0, 0, 4, 0);
        //        7.addLine(4, 0, 4, 6);
        //               
        //        letters['7'] = 7;
        //        
        //        Letter 8;
        //        8.addLine(0, 0, 4, 0);
        //        8.addLine(4, 0, 4, 6);
        //        8.addLine(4, 6, 0, 6);
        //        8.addLine(0, 6, 0, 0);
        //        8.addLine(0, 3, 4, 3);
        //        
        //        letters['8'] = 8;
        //        
        //        
        //        Letter 9;
        //        9.addLine(4, 3, 0, 3);
        //        9.addLine(0, 3, 0, 0);
        //        9.addLine(4, 6, 0, 6);
        //        9.addLine(0, 0, 4, 0);
        //        9.addLine(4, 0, 4, 6);
        //        
        //        letters['9'] = 9;

		
	}
	
	
	map <int, Letter> letters;
	
	
};