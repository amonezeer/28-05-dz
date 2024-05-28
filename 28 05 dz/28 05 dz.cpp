#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

class PowerSupply {
public:
    void supplyPower() {
        simulateAction("PowerSupply: Подано питание. ");
    }
    void stopPower() {
        simulateAction("PowerSupply: Питание отключено. ");
    }
    void supplyPowerToGPU() {
        simulateAction("PowerSupply: Питание подано на видеокарту. ");
    }
    void supplyPowerToRAM() {
        simulateAction("PowerSupply: Питание подано на оперативную память. ");
    }
    void supplyPowerToDiskDrive() {
        simulateAction("PowerSupply: Питание подано на устройство чтения дисков. ");
    }
    void supplyPowerToHardDrive() {
        simulateAction("PowerSupply: Питание подано на винчестер. ");
    }

private:
    void simulateAction(const string& action) {
        cout << action;
        if (rand() % 2 == 0) {
            cout << "Успешно.\n";
        }
        else {
            cout << "Неуспешно.\n";
        }
    }
};

class Sensors {
public:
    void checkVoltage() {
        simulateAction("Sensors: Проверка напряжения. ");
    }
    void checkPowerSupplyTemperature() {
        simulateAction("Sensors: Проверка температуры блока питания. ");
    }
    void checkGPUTemperature() {
        simulateAction("Sensors: Проверка температуры видеокарты. ");
    }
    void checkRAMTemperature() {
        simulateAction("Sensors: Проверка температуры оперативной памяти. ");
    }
    void checkAllSystemTemperatures() {
        simulateAction("Sensors: Проверка температуры всех систем. ");
    }

private:
    void simulateAction(const string& action) {
        cout << action;
        if (rand() % 2 == 0) {
            cout << "Успешно.\n";
        }
        else {
            cout << "Неуспешно.\n";
        }
    }
};

class GPU {
public:
    void start() {
        simulateAction("GPU: Запуск видеокарты. ");
    }
    void checkConnection() {
        simulateAction("GPU: Проверка связи с монитором. ");
    }
    void displayRAMData() {
        simulateAction("GPU: Вывод данных об оперативной памяти. ");
    }
    void displayDiskDriveData() {
        simulateAction("GPU: Вывод информации об устройстве чтения дисков. ");
    }
    void displayHardDriveData() {
        simulateAction("GPU: Вывод данных о винчестере. ");
    }
    void displayFarewellMessage() {
        simulateAction("GPU: Прощальное сообщение. ");
    }

private:
    void simulateAction(const string& action) {
        cout << action;
        if (rand() % 2 == 0) {
            cout << "Успешно.\n";
        }
        else {
            cout << "Неуспешно.\n";
        }
    }
};

class RAM {
public:
    void start() {
        simulateAction("RAM: Запуск устройств оперативной памяти. ");
    }
    void analyzeMemory() {
        simulateAction("RAM: Анализ памяти. ");
    }
    void clearMemory() {
        simulateAction("RAM: Очистка памяти. ");
    }

private:
    void simulateAction(const string& action) {
        cout << action;
        if (rand() % 2 == 0) {
            cout << "Успешно.\n";
        }
        else {
            cout << "Неуспешно.\n";
        }
    }
};

class DiskDrive {
public:
    void start() {
        simulateAction("DiskDrive: Запуск устройства чтения дисков. ");
    }
    void checkDisk() {
        simulateAction("DiskDrive: Проверка наличия диска. ");
    }
    void returnToInitialPosition() {
        simulateAction("DiskDrive: Устройство чтения дисков возвращено в исходное положение. ");
    }

private:
    void simulateAction(const string& action) {
        cout << action;
        if (rand() % 2 == 0) {
            cout << "Успешно.\n";
        }
        else {
            cout << "Неуспешно.\n";
        }
    }
};

class HardDrive {
public:
    void start() {
        simulateAction("HardDrive: Запуск винчестера. ");
    }
    void checkBootSector() {
        simulateAction("HardDrive: Проверка загрузочного сектора. ");
    }
    void stop() {
        simulateAction("HardDrive: Винчестер остановлен. ");
    }

private:
    void simulateAction(const string& action) {
        cout << action;
        if (rand() % 2 == 0) {
            cout << "Успешно.\n";
        }
        else {
            cout << "Неуспешно.\n";
        }
    }
};

class ComputerFacade {
private:
    PowerSupply powerSupply;
    Sensors sensors;
    GPU gpu;
    RAM ram;
    DiskDrive diskDrive;
    HardDrive hardDrive;

public:
    ComputerFacade() {
        srand(static_cast<unsigned>(time(0)));
    }

    void beginWork() {
        powerSupply.supplyPower();
        sensors.checkVoltage();
        sensors.checkPowerSupplyTemperature();
        sensors.checkGPUTemperature();
        powerSupply.supplyPowerToGPU();
        gpu.start();
        gpu.checkConnection();
        sensors.checkRAMTemperature();
        powerSupply.supplyPowerToRAM();
        ram.start();
        ram.analyzeMemory();
        gpu.displayRAMData();
        powerSupply.supplyPowerToDiskDrive();
        diskDrive.start();
        diskDrive.checkDisk();
        gpu.displayDiskDriveData();
        powerSupply.supplyPowerToHardDrive();
        hardDrive.start();
        hardDrive.checkBootSector();
        gpu.displayHardDriveData();
        sensors.checkAllSystemTemperatures();
    }

    void shutdown() {
        hardDrive.stop();
        ram.clearMemory();
        ram.analyzeMemory();
        gpu.displayFarewellMessage();
        diskDrive.returnToInitialPosition();
        powerSupply.stopPower();
    }
};

int main() {
    system("chcp 1251");

    ComputerFacade computer;
    cout << "Запуск компьютера:\n";
    computer.beginWork();

    cout << "\nВыключение компьютера:\n";
    computer.shutdown();

    return 0;
}
