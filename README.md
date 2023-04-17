# Güncelleme yöneticisi

### Örnek Kullanım:
```
#include "updatecontroller.h"
UpdateController update;
update.setParameters("https://api.github.com/repos/atakli/PrayerReminder-Desktop/releases/latest", appName, "NamazVaktiHatirlatici.exe", versionFileFullPath);
update.isNewVersionAvailable();
```

İlk argüman github api adresi. İkinci, uygulamanın dosya yolu. Üçüncüsü, github reposundan indirilecek dosya ismi.

Son argüman olan `versionFileFullPath` isteğe bağlıdır. Verilmezse programın varsayılan çalışma yolunda "version.txt" isminde bir dosya varmış gibi işlem yapılır.<br>
isNewVersionAvailable'a true geçildiğinde programın güncel olduğunda da haber verir. Yoksa sadece güncel değilse haber verir.

version.txt dosyasının içeriği v0.4.2-Windows formatında olmalıdır.

Statik veya dinamik oalrak derlenen kütüphane dosyası link edilmelidir.

Ayrıca bir dosya indirmek için de downloadFile fonksiyonu kullanılabilir: 
```
update.downloadFile(evkatOnlinePath, url);
```
Argümanlar sırasıyla, dosyanın bilgisayarda indirileceği tam yolu ve web adres linki.

### TODO:
* indirilirken progress bar göster
* güncel versiyonu indirirken ProtocolUnknownError veriyor. Üstelik sonra yine de indirdim diyor.
