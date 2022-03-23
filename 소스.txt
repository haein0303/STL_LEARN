// ============================================================================
//									STL
// 
//	2022.3.7 월34              월23수34                   (1주1일)
// 
//	C++ 복습
// 
// 
// ============================================================================
#INCLUDE<IOSTREAM>


TEMPLATE <CLASS T> // TYPENAME OR CLASS 중 선택
VOID CHANGE_T(T& A, T& B) { //탬플릿은 선언과 정의를 동시에 진행
	T TMP{ A };
	A = B;
	B = TMP;
}


CLASS DOG {
PUBLIC:
	INT LOCAL_NUM;
	STD::STRING NAME;
	INT AGE;
PUBLIC:
	DOG(INT N) : LOCAL_NUM{ N } {	}
	DOG(STD::STRING STR, INT AGE) :NAME{ STR }, AGE{ AGE } { }
	FRIEND STD::OSTREAM& OPERATOR<< (STD::OSTREAM&, CONST DOG&);

	OPERATOR INT() {
		RETURN LOCAL_NUM;
	}
};

STD::OSTREAM& OPERATOR<<(STD::OSTREAM& OS, CONST DOG& DOG) {
	OS << DOG.LOCAL_NUM;
	RETURN OS;
}


VOID CHANGE(AUTO& A, AUTO& B) {
	AUTO TMP{ B };
	B = A;
	A = TMP;
}

/*INT MAIN()
{

	USING NAMESPACE STD::LITERALS;
	//	COUT << "STRING SIZE : " << SIZEOF(STRING) << ENDL;
	//	COUT << "STRING_VIEW SIZE : " << SIZEOF(STRING_VIEW) << ENDL;
	DOG A{ 1 };
	DOG B{ 2 };
	STD::STRING C = "STL";
	STD::STRING D = "C++";
	DOG E{ "코코",3 };
	DOG F{ "댕댕",5 };

	CHANGE(A, B);
	CHANGE(C, D);
	CHANGE(E, F);

	STD::COUT << " A : "S << A << " B : "S << B << STD::ENDL;
	STD::COUT << " C : " << C << " D : " << D << STD::ENDL;
	STD::COUT << " E : NAME : " << E.NAME << " AGE : " << E.AGE << STD::ENDL;
	STD::COUT << " F : NAME : " << F.NAME << " AGE : " << F.AGE << STD::ENDL;

	SAVE("SAVE.H");
	SAVE("SAVE.CPP");
	SAVE("MAIN.CPP");
}
*/