// 반복자(iterator)
// 복합객체(컨테이너)의 내부 구조에 상관없이 동일한 방식으로
// 모든 요소를 열거하게 하는 패턴

//						C#, java등				C++
// 사용법이 동일		인터페이스 설계			포인터의 동작방식과 같게하자
//												문서로만 약속(인터페이스 아님)
// 반복자 꺼내기		s.GetEnumerator()		s.begin()  힙객체 아님.
//						힙객체(C++이면delete필요)

// 반복자 이동			p.MoveNext(), 가상함수	++p, 인라인 치환

// Find함수 만들기		find(인터페이스*)		find( T)
//												템플릿 이므로 find함수 여러개 생성됨
//