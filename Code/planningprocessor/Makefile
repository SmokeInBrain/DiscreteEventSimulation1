#
# Planning Processor
# by SmokeInBrain and DWladdimiroC

INC_DIRS = -Isrc

CFLAGS = -c -w

main: build/main.o build/Event.o build/Process.o build/StatisticsIn.o build/StatisticsOut.o build/File.o build/Processing.o build/Distribution.o build/Random.o build/VectorEvent.o build/VectorProcess.o
	@ g++ build/*.o -o bin/planningProcessor.run
	@ echo "The compilation has been completed successfully"

build/main.o: src/main.cpp
	@ echo " src/main.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/main.cpp -o build/main.o

build/Event.o: src/eda/Event.cpp
	@ echo " src/eda/Event.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/Event.cpp -o build/Event.o

build/Process.o: src/eda/Process.cpp
	@ echo " src/Process.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/Process.cpp -o build/Process.o

build/StatisticsIn.o: src/eda/StatisticsIn.cpp
	@ echo " src/StatisticsIn.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/StatisticsIn.cpp -o build/StatisticsIn.o

build/StatisticsOut.o: src/eda/StatisticsOut.cpp
	@ echo " src/StatisticsOut.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/eda/StatisticsOut.cpp -o build/StatisticsOut.o

build/File.o: src/filereading/File.cpp
	@ echo " src/File.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/filereading/File.cpp -o build/File.o

build/Processing.o: src/processing/Processing.cpp
	@ echo " src/processing/Processing.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/processing/Processing.cpp -o build/Processing.o

build/Distribution.o: src/random/Distribution.cpp
	@ echo " src/random/Distribution.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/random/Distribution.cpp -o build/Distribution.o

build/Random.o: src/random/Random.cpp
	@ echo " src/random/Random.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/random/Random.cpp -o build/Random.o

build/VectorEvent.o: src/vector/VectorEvent.cpp
	@ echo " src/vector/VectorEvent.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/vector/VectorEvent.cpp -o build/VectorEvent.o

build/VectorProcess.o: src/vector/VectorProcess.cpp
	@ echo " src/vector/VectorProcess.cpp"
	@ g++ $(CFLAGS) $(INC_DIRS) src/vector/VectorProcess.cpp -o build/VectorProcess.o

clean:
	@ clear
	@ echo "Clear folder.."
	@ rm -rf build/*
	@ rm -rf bin/*

run:
	@ clear
	@ echo "Execute"
	@ ./bin/planningProcessor.run -i input/inputExample.txt -o output/outputExample.txt -l log/logExample.txt

testProgram:
	@ echo "Execute test"
	@ ./bin/planningProcessor.run -i input/input1.txt -o output/output1v1.txt -l log/log1v1.txt
	@ ./bin/planningProcessor.run -i input/input1.txt -o output/output1v2.txt -l log/log1v2.txt
	@ ./bin/planningProcessor.run -i input/input1.txt -o output/output1v3.txt -l log/log1v3.txt
	@ ./bin/planningProcessor.run -i input/input1.txt -o output/output1v4.txt -l log/log1v4.txt
	@ ./bin/planningProcessor.run -i input/input1.txt -o output/output1v5.txt -l log/log1v5.txt

	@ ./bin/planningProcessor.run -i input/input2.txt -o output/output2v1.txt -l log/log2v1.txt
	@ ./bin/planningProcessor.run -i input/input2.txt -o output/output2v2.txt -l log/log2v2.txt
	@ ./bin/planningProcessor.run -i input/input2.txt -o output/output2v3.txt -l log/log2v3.txt
	@ ./bin/planningProcessor.run -i input/input2.txt -o output/output2v4.txt -l log/log2v4.txt
	@ ./bin/planningProcessor.run -i input/input2.txt -o output/output2v5.txt -l log/log2v5.txt

	@ ./bin/planningProcessor.run -i input/input3.txt -o output/output3v1.txt -l log/log3v1.txt
	@ ./bin/planningProcessor.run -i input/input3.txt -o output/output3v2.txt -l log/log3v2.txt
	@ ./bin/planningProcessor.run -i input/input3.txt -o output/output3v3.txt -l log/log3v3.txt
	@ ./bin/planningProcessor.run -i input/input3.txt -o output/output3v4.txt -l log/log3v4.txt
	@ ./bin/planningProcessor.run -i input/input3.txt -o output/output3v5.txt -l log/log3v5.txt

	@ ./bin/planningProcessor.run -i input/input4.txt -o output/output4v1.txt -l log/log4v1.txt
	@ ./bin/planningProcessor.run -i input/input4.txt -o output/output4v2.txt -l log/log4v2.txt
	@ ./bin/planningProcessor.run -i input/input4.txt -o output/output4v3.txt -l log/log4v3.txt
	@ ./bin/planningProcessor.run -i input/input4.txt -o output/output4v4.txt -l log/log4v4.txt
	@ ./bin/planningProcessor.run -i input/input4.txt -o output/output4v5.txt -l log/log4v5.txt

program: clean main run
