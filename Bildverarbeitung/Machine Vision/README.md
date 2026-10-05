# OpenCV mit C++ unter Windows einrichten

Für die Bildverarbeitungsübungen wird **OpenCV 5** zusammen mit **MSYS2 UCRT64** und `g++` verwendet.

## 1. OpenCV installieren

In der **MSYS2 UCRT64 Shell**:

```bash
pacman -S mingw-w64-ucrt-x86_64-opencv
```

Anschließend prüfen, ob OpenCV korrekt installiert wurde:

```powershell
pkg-config --modversion opencv5
```

Bei dieser Installation wird OpenCV über folgendes Paket angesprochen:

```text
opencv5
```

---

## 2. Compiler prüfen

In PowerShell:

```powershell
where.exe g++
```

Verwendet werden sollte der UCRT64-Compiler:

```text
C:\msys64\ucrt64\bin\g++.exe
```

---

## 3. Programm mit OpenCV kompilieren

Zuerst werden die benötigten Compiler- und Linker-Flags von OpenCV geladen:

```powershell
$cv = (pkg-config --cflags --libs opencv5) -split '\s+'
```

Danach kann das Programm kompiliert werden:

```powershell
g++ -std=c++17 main.cpp -o main.exe $cv
```

Programm starten:

```powershell
.\main.exe
```

Der komplette Build- und Startvorgang:

```powershell
$cv = (pkg-config --cflags --libs opencv5) -split '\s+'
g++ -std=c++17 main.cpp -o main.exe $cv
.\main.exe
```

---

## 4. Windows PATH

Damit die benötigten OpenCV-DLLs beim Start gefunden werden, muss folgender Ordner im Windows-`PATH` enthalten sein:

```text
C:\msys64\ucrt64\bin
```

Falls das Programm erfolgreich kompiliert, sich beim Start aber sofort beendet, sollte zuerst geprüft werden, ob dieser Pfad korrekt gesetzt ist.

---

## 5. VS Code IntelliSense

Damit VS Code die OpenCV-Header korrekt findet, können folgende Include-Pfade eingetragen werden:

```text
C:/msys64/ucrt64/include
C:/msys64/ucrt64/include/opencv5
```

OpenCV kann danach beispielsweise so eingebunden werden:

```cpp
#include <opencv2/opencv.hpp>
```

---

## Testprogramm

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("image.jpg");

    if (img.empty())
    {
        std::cerr << "Bild konnte nicht geladen werden.\n";
        return 1;
    }

    cv::imshow("Image", img);
    cv::waitKey(0);

    return 0;
}
```

Kompilieren:

```powershell
$cv = (pkg-config --cflags --libs opencv5) -split '\s+'
g++ -std=c++17 main.cpp -o main.exe $cv
```

Starten:

```powershell
.\main.exe
```