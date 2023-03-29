#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>

void TestPrint(std::string& str)
{
	std::cout << str.length() << ":" << str << std::endl;
}

int main()
{
	//표준라이브러리(Standard Libary:STL)
	
	//1.컨테이너(Container)
	//자료구조를 위한 템플릿 클래스, stack,Queue,List등과 같이 원소를 관리하는 집합과 같은 공간 다른말로는 컬렉션(Collection)

	//2.반복자(Iterator)
	//컨테이너의 원소들을 순회하기 위한 일반화된 방법이며 다음과 같은 공통기능이 있다.
	// 포인터 개념:원소를 가르킴
	// 원소 순회:++,!=,==등의 연산자 지원
	// 시작, 끝 제공:begin(),end()

	//3.알고리즘(Algorithm)
	//정렬,검색,복사 부터 구현하기 어려운 기능들을 준비해둔 알고리즘 집합 모든 컨테이너에게 적용할수 있는 장점이 있다.

	//std::string
	std::string s1{ "123" };
	std::string s2{ "456" };
	
	s1 = s2; //문자열 대입
	s1 += s2; //문자열 더한 후 대입
	s1[0]; //첨자첩근
	s1 + s2; //두 문자열 더한 string 객체 반환
	s1 == s2; //두 문자열 비교
	s1 != s2; //두 문자열 비교
	s1.size(); //문자열의 크기
	s1.length(); //문자열의 길이
	s1.c_str(); //std::string을 char*형태로 변환
	s1.insert(s1[1], s2); //s1의 position에 s2를 삽입
	s1.append(s2); //s1의 가장 뒤에 s2를 붙임
	s1.erase(s1[1]); //s1[pos] 부터 시작하는 문자를 지움
	s1.erase(s1[0], 4); //s1[pos]부터 n개의 문자를 지움

	std::getline(std::cin, s1); //cin으로 부터 문장을 s1에 읽음

	//예제
	std::string empty;
	TestPrint(empty);

	std::string sized(10, '\0');
	TestPrint(sized);

	std::string s3("test");
	std::cout << s3[0] << s3[1] << s3[2] << s3[3] << std::endl;

	std::string s4(s3);
	std::string s5 = s3 + s4;
	TestPrint(s3);
	s3 += s3;
	s3[0] = 'T';
	TestPrint(s3);

	empty = s3;
	TestPrint(empty);

	empty = empty;
	TestPrint(empty);


	//문자열과 다른 타입의 변환
	int number{ 123 };
	std::string str{ "" };

	str=std::to_string(number); //정수123을 문자열로 변환
	number = std::stoi(str); //문자열을 정수로 변환

	std::cout << str << "<->" << number << std::endl;
	
	
	//문자열 스트림
	int number{ 1 };
	char name[]{ "Doggy" };
	float average{ 90.1f };
	char output[128]{};
	std::ostringstream os; //문자를 화면에 출력하는 스트림
	os << number << "번 학생" << name << "는 평균" << average << "입니다." << std::endl;
	
	std::string buffer = os.str();

	//포멧 스트림
	int myInt = 123;
	float myFloat = 3.141592f;
	bool myBool = true;
	std::cout << myBool << std::endl; //1출력
	std::cout << std::boolalpha << myBool << std::endl; //true출력
	std::cout << std::dec << myInt << std::endl; //10진수 123
	std::cout << std::hex << myInt << std::endl; //16진수 7b
	std::cout << std::oct << myInt << std::endl; //8진수 173
	std::cout << std::bitset<8>(myInt).to_string() << std::endl; //01111011
	std::cout.precision(3); //정밀도 지정
	std::cout << myFloat << std::endl; //3.14
	std::cout.width(10); //너비 지정
	std::cout << myInt << std::endl;//        173 
	std::cout.fill('0'); //여백을 채울 문자 지정
	std::cout.width(10);//너비 지정
	std::cout << std::right << myInt << std::endl; //오른쪽 정렬

	//벡터(vector)
	//벡터를 사용하기 위해서는 #include <vector>명시

	std::vector<int> v{ 2,3,1,5,6 }; 
	std::vector<std::string> names{ "doggy","kitty","bunny","piggy" }; 

	std::vector<int> n(5); //크기 지정
	std::cout << v[0]; //v[0]의 값 2를 출력
	v[1] = 9; //v[1]의 값에 9를 대입

	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << std::endl; //출력
	}
}

