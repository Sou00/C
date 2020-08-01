//Igor Lonak

int Counter = 0;
int Display = 31;

int dodaj( int a, int b ){
    int c;
	int d;

    if ( b == 0 ) return a;

	c = a ^ b;
    d = ( a & b ) << 1;

	return dodaj( c, d );
}

void Emplace( std::string input, int* a ){
	if( Counter == 0 )
		*a = 0;

	if( Counter < input.length() ){
		if( input.at( Counter ) == '0' ||  input.at( Counter ) == '1' ){
			int readSet = 1;

			if( input.at( Counter ) == '1' )
				readSet <<= 16;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 8;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 4;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 2;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 1;

			*a |= readSet;
		}

		Counter = dodaj( Counter, 1 );
		Emplace( input, a );
	}
	else
		Counter = 0;
}

void Insert( std::string input, int* a ){
	if( Counter < input.length() ){
		if( input.at( Counter ) == '0' ||  input.at( Counter ) == '1' ){
			int readSet = 1;

			if( input.at( Counter ) == '1' )
				readSet <<= 16;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 8;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 4;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 2;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 1;

			*a |= readSet;
		}

		Counter = dodaj( Counter, 1 );
		Insert( input, a );
	}
	else
		Counter = 0;
}

void Erase( std::string input, int* a ){
	if( Counter < input.length() ){
		if( input.at( Counter ) == '0' ||  input.at( Counter ) == '1' ){
			int readSet = 1;

			if( input.at( Counter ) == '1' )
				readSet <<= 16;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 8;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 4;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 2;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				readSet <<= 1;

			readSet = ~readSet;
			*a &= readSet;
		}

		Counter = dodaj( Counter, 1 );
		Erase( input, a );
	}
	else
		Counter = 0;
}

void Print( int a, std::string* output ){
	if( Display < 0 ){
		Display = 31;
		return;
	}

	if( a == 0 ){
		Display = 31;
		*output = "empty";
		return;
	}

	if( Display == 31 )
		*output = "";

	if( a & ( 1 << Display ) ){
		std::stringstream ss;
		ss << *output;
		ss << ( Display / 16 )
		   << ( Display / 8 ) % 2
		   << ( Display / 4 ) % 4 % 2
		   << ( Display / 2 ) % 8 % 2
		   << ( Display % 2 ) << " ";
		*output = ss.str();
	}

	Display = dodaj( Display, dodaj( 1, ~1) );
	Print( a, output );
}

bool Emptiness( int a ){
	return ( a == 0 );
}

bool Nonempty( int a){
	return ( a != 0 );
}

bool Member( std::string input, int a ){
	if( Counter < input.length() ){
		if( input.at( Counter ) == '0' ||  input.at( Counter ) == '1' ){
			int b = 1;

			if( input.at( Counter ) == '1' )
				b <<= 16;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				b <<= 8;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				b <<= 4;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				b <<= 2;
			Counter = dodaj( Counter, 1 );

			if( input.at( Counter ) == '1' )
				b <<= 1;

			Counter = 0;
			return ( a & b );
		}

		Counter = dodaj( Counter, 1 );
		return Member( input, a );
	}
	else{
		Counter = 0;
		return 0;
	}
}

bool Disjoint( int a, int b ){
	return  ( a & b ) == 0;
}

bool Conjunctive( int a, int b ){
	return ( a & b ) != 0;
}

bool Equality( int a, int b ){
	return ( a == b );
}

bool Inclusion( int a, int b ){
	return ( ( a | b ) == b );
}

void Union( int a, int b, int* output ){
	*output = a | b;
}

void Intersection( int a, int b, int* output ){
	*output = a & b;
}

void Symmetric( int a, int b, int* output ){
	*output = a ^ b;
}

void Difference( int a, int b, int* output ){
	*output = ( a & ( ~b ) );
}

void Complement( int a, int* output ){
	*output = ~a;
}

int policz( int a, int i = 0 ){
	if( i < 32 ){
		if( a & ( 1 << i ) ) {
			return dodaj( policz( a, dodaj( i, 1 ) ), 1 );
		}
		return policz( a, dodaj( i, 1 ));
	}

	return 0;
}

bool LessThen( int a, int b ){
	return ( policz( a ) < policz( b ) )
	    || ( policz( a ) == policz( b )  &&  (unsigned int)a < (unsigned int)b );
}

bool LessEqual( int a, int b ){
	return ( policz( a ) < policz( b ) )
	    || ( policz( a ) == policz( b )  &&  (unsigned int)a <= (unsigned int)b );
}

bool GreatEqual( int a, int b ){
	return ( policz( a ) > policz( b ) )
	    || ( policz( a ) == policz( b )  &&  (unsigned int)a >= (unsigned int)b );
}

bool GreatThen( int a, int b ){
	return ( policz( a ) > policz( b ) )
	    || ( policz( a ) == policz( b )  &&  (unsigned int)a > (unsigned int)b );
}

