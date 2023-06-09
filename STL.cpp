﻿#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <array>
#include <forward_list>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>

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
	
	//c++범위기반 반복(rage-based loop)

	for (int x : v)
	{
		std::cout << x << std::endl;
	}

	//vector의 크기 변경
	v.push_back(4); //v[4]뒤에 4가 들어감 크기는 6
	v.push_back(7); //v[5]뒤에 7이 들어감 크기는 7;

	std::vector<int> vector{};
	std::cout << "숫자를 공백으로 구분하여 입력하세요!" << std::endl;
	std::cout << "입력 종료는 숫자가 아닌 문자를 입력하시면 됩니다." << std::endl;

	for (int value; std::cin >> value;)
	{
		v.push_back(value);
	}

	int sum{};
	for (int element : v)
	{
		sum += element;
	}

	float average = static_cast<float>(sum) / v.size();

	std::cout << "합:" << sum << std::endl;
	std::cout << "평균" << average << std::endl;

	//주의!
	std::vector<int> number1{ 3 }; //값이 3인 원소가 들어가 있음
	std::vector<int> number2(3); //크기가 3이며 기본값이 0이 들어가 있음

	//반복자
	//반복자는 컨테이너를 순회하기 위한 포인터
	std::vector<int> v2{ 1,2,3 };
	std::vector<int>::iterator itr = v2.begin(); //itr이 v2의 첫번쨰 원소를 가르키고 있음

	while (itr != v.end())
	{
		std::cout << *itr; //역참조 해서 출력
		itr++; 
	}

	for (std::vector<int>::iterator itr2 = v2.begin(); itr2 != v.end(); ++itr2)
	{
		std::cout << *itr2;
	}

	for (auto itr3 = v.begin(); itr3 != v.end(); ++itr)
	{
		std::cout << *itr;
	}

	for (int& val : v2)
	{
		val = val * val; //참조형을 사용해 값을 변경
	}


	//람다식(c++11)
	[](int a, int b) {}; //매개변수 2개를 받는 익명함수
	[](int a)->int {return a; }; //매개변수 1개와 반환값이 있는 익명함수

	//for each
	//범위기반 반복문과 비슷한 기능, 헤더에 algorithm포함

	std::vector<int> v4{ 1,2,3 };
	std::for_each(v4.begin(), v4.end(), [](const int& val)
		{
			std::cout << val;
		});

	//STL 컨테이너 정리
	//순차 컨테이너: array 배열
	//             : vector 가변배열
	//             : forward_list 단일 연결 리스트
	//             : list 양방향 연결 리스트
	//             : deque 양방향 큐
	//원소들이 순서대로 나열되어 있는 컨테이너, 원소를 추가해도 순서유지

	//보조 컨테이너: stack 스택
	//             : queue 큐
	//             : priority_queue 우선순위 적용된 큐
	//특정한 목적에 맞도록 변형된 컨테이나 
	
	//연관 컨테이너: set 이진 탐색 트리 기반 단일 키
	//             : multiset 여러개의 키를 가진 set
	//             : map 이진 탐색 트리 기반(key,value)
	//             : multimap 여러개의 키를 가진 map
	//원소들이 좌/우 혹은 상/하로 서로 관련이 있는 컨테이너, 원소들끼리 부모자식의 관계를 가지기도 한다, 원소를 추가하면 정렬이 된다.

	//오버헤더(overgead)
	//간접비용, 기대하는 저장공간 외에 추가되는 값을 말한다.

	//메모리 접근 방식
	//임의 접근(random access):원소가 포함된 메모리를 상수 시간에 가져올 수 있다.
	//순자 접근(sequential access):처음 혹은 끝 부터 순서대로 접근해서 원소를 가져온다.

	//std::array
	//#include<array>
	//std::array의 특징
	//1.순차적(Sequence)
	//정해진 순서로 저장되며, 각 원소를 순서대로 접근 가능
	//2.연속된 저장 공간(Contiguous)
	//연속된 메모리에 저장되어 포인터로 이동이 가능,랜덤 액세스 가능
	//3.고정크기
	//array의 크기는 컴파일 시간 상수,일반 배열과 마찬가지로 정확히 원소 개수 만큼 메모리를 차지

	std::array<int, 4>array{ 0,1,2,3 };

	for (auto value : array) 
	{
		std::cout << value;
	}

	for (auto iter = array.begin(); iter != array.end(); ++iter)
	{
		*iter = *iter + 1;
	}

	for (int i = 0; i < array.size(); ++i)
	{
		std::cout << array[i] << " ";
	}

	//std::vector
	//#inlcude<vector>
	//1.순차적(Sequence)
	//정해진 순서로 저장되며, 각 원소를 순서대로 접근 가능
	//2.동적 배열(Dynamic Array)
	//배열 크기를 변경할 수 있으며, 포인터 연산을 통해 바로 접근 가능
	//3.메모리 할당자(Memory Allocator)
	//할당자(allocator)를 통해 추가할 원소의 메모리 할당을 동적으로 처리 가능


	//std::forward_list
	//#inlcude<forward_list>
	//1.순차적(Sequence)
	//정해진 순서로 저장되며, 각 원소를 순서대로 접근 가능
	//2.단일 연결 리스트(Single Linked List)
	//특정 원소 이후에 상수 시간에 삽입/삭제 가능, 입의 접근 불가능
	//3.메모리 할당자(Memory Allocator)
	//할당자(allocator)를 통해 추가할 원소의 메모리 할당을 관리

	std::forward_list<int> list{ 10,11,20,21 };
	
	auto it = std::find(list.begin(), list.end(), 11); //값을 찾아 반복자 반환
	it =list.insert_after(it, 12); //반복자 뒤에 값을 삽입하고 반복자 반환

	std::forward_list<int> list2{ 10,11 };
	list.splice_after(it, list2); //list에 list2의 원소들을 붙이고 list2의 원소 모두 비워진다.
	list.sort();//리스트 정렬

	list.unique([](int a, int b)
		{
			return a == b; //중복되는 값을 제거한다.정렬이 되어야만 작동한다.
		}); 

	list.erase_after(list.begin()); //반복자 다음 원소를 지운다.
	
	//std::list
	//#include<list>
	//1.순차적(Sequence)
	//정해진 순서로 저장되며, 각 원소를 순서대로 접근 가능
	//2.이중 연결 리스트(Dobule Linked List)
	//특정 원소 이후에 상수 시간에 삽입/삭제 가능, 입의 접근 불가능
	//3.메모리 할당자(Memory Allocator)
	//할당자(allocator)를 통해 추가할 원소의 메모리 할당을 관리

	std::list<int> list{ 1,2,3 };

	list.reverse(); //원소 역순으로 나열 {3,2,1}

	std::list<int> list2{ 4,5,6 };
	
	list2.merge(list); //list의 원소들을 list2로 옮겨 하나로 병합 단 둘다 정렬이 되어 있어야함

	//std::deque
	//#include<deque>
	//1.순차적(Sequence)
	//정해진 순서로 저장되며, 각 원소를 순서대로 접근 가능
	//2.동적 배열(Dynamic Array)
	//배열 크기 변경 가능하며, 포인터 연산을 통해 접근 가능
	//3.메모리 할당자(Memory Allocator)
	//할당자(allocator)를 통해 추가할 원소의 메모리 할당을 관리
	//4.vector는 단일 배열을 사용하나 deque는 서로 다른 메모리 공간으로 분산될수 있다.

	std::deque<int> deque{ 3,4,5 };
	deque.push_front(1); //앞에 값을 추가
	deque.push_back(6); //뒤에 값을 추가
	deque.pop_front(); //앞에서 값을 꺼낸다.
	deque.pop_back(); //뒤에서 값을 꺼낸다.

	//std::stack
	//#include<stack>

	std::stack<int> stack;
	stack.push(1); //뒤에 값을 추가
	stack.push(2); //뒤에 값을 추가
	stack.push(3); //뒤에 값을 추가
	stack.pop(); //뒤에 값을 꺼낸다.

	std::stack<int> tempStack(stack); //순회가 불가하므로 객체를 하나 새로 만들어서 원래의 스택에 들어있는 값들을 복사생성자 동적이므로 깊은복사를 통해 넣어준다.
	while (!tempStack.empty()) //값을 비울때까지 반복
	{
		std::cout << tempStack.top() << " "; //출력
		tempStack.pop(); //값을 꺼낸다.
	}
	
	//std::queue
	//#include<queue>

	std::queue<int> queue;
	queue.push(1); //값을 추가
	queue.push(2); 
	queue.push(3);
	queue.pop();

	std::queue<int> tempQueue(queue); 
	while (!tempQueue.empty())
	{
		std::cout << tempQueue.front() << " ";
		tempQueue.pop();
	}
	
	//std::set->이진 탐색 트리(binary search tree)
	//#include<set>
	//1.연관적(associative)
	//순서나 위치에 의해 원소를 참조하는 것이 아니라, 키(key)로 참조
	//2.순서 집합(ordered)
	//원소가 추가될때 지정된 비교함수에 의해 정렬된다.
	//3.고유성(unique)
	//동일한 키는 존재하지 않는다.
	//4.메모리 할당자(Memory Allocator)
	//할당자(allocator)를 통해 추가할 원소의 메모리 할당을 관리

	std::set<int> set;
	set.insert(1);
	set.insert(6);
	set.insert(2);
	set.insert(5); //자동으로 정렬된다 {1,2,5,6}

	set.erase(2); //원소제거 {1,5,6}

	std::set<int>::iterator setIter = set.begin(); //반복자를 통한 순회가능
	while (setIter != set.end())
	{
		std::cout << *setIter << " ";
		setIter++;
	}

	//std::map
	//#include<map>
	//map은 <key,value>으로 구성된 원소를 가진다.
	//key 식별자, value 실제 원소의 값
	//1.연관적(associative)
	//순서나 위치에 의해 원소를 참조하는 것이 아니라, 키(key)로 참조
	//2.순서 집합(ordered)
	//원소가 추가될때 지정된 비교함수에 의해 정렬된다.
	//3.고유성(unique)
	//동일한 키는 존재하지 않는다.
	//4.메모리 할당자(Memory Allocator)
	//할당자(allocator)를 통해 추가할 원소의 메모리 할당을 관리

	std::map<std::string, std::string> myDictionary;

	myDictionary.insert(std::pair<std::string, std::string>("array", "단순 배열"));

	myDictionary.insert(std::pair<std::string, std::string>("vector", "동적 배열"));

	myDictionary.insert(std::pair<std::string, std::string>("stack", "LIFO 구조"));

	std::cout << "array" << myDictionary["array"] << std::endl;

	for (auto pair : myDictionary)
	{
		std::cout << pair.first << ":" << pair.second << std::endl;
	}
		
}

