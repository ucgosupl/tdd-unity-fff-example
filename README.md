Przykładowy kod do artykułu:
https://ucgosu.pl/2021/03/cmake-jak-uzywac-w-wiekszych-projektach/

Wykorzystanie CMake z wieloma targetami.

Projekt zawiera szablon unit testu.
Foldery:
src - kod produkcyjny. Zawiera funkcje, które będziemy testować
test/Unity - framework do unit testów Unity
test/fff - biblioteka header only do mocków Fake Function Framework
test/cyclic_buffer - testy funkcji bufora cyklicznego
test/cyclic_buffer - testy funkcji bufora cyklicznego z użyciem fff

Plik CMakeLists.txt dla Unity tworzy bibliotekę statyczną.
Plik CMakeLists.txt dla FFF tworzy bibliotekę header only.
Pliki CMakeLists.txt dla testów bufora cyklicznego tworzą aplikacje wykorzystujące te biblioteki.

Dzięki zastosowaniu targetów z CMake mamy kontrolę nad includami, flagami kompilacji itp. dla bibliotek i dla aplikacji. Możemy zmieniać ich widoczność za pomocą atrybutów PRIVATE, PUBLIC, INTERFACE.
