## Инструмент ipcalc
 * 1.1. Сети и маски <br>
    Определи и запиши в отчёт: <br>

    + 1) Адрес сети 192.167.38.54/13 : 192.160.0.0/13 <br>
        ![alt text](screenshots/network.png)<br>

    + 2) Перевод маски 255.255.255.0 в префиксную и двоичную запись: /24 11111111 11111111 11111111 00000000 <br>
        /15 в обычную и двоичную: 255.254.0.0, 11111111 1111111 0 00000000 00000000 <br>
        11111111.11111111.11111111.11110000 в обычную и префиксную: 255.255.255.240 , /28 <br>

    + 3) Минимальный и максимальный хост в сети 12.167.38.4 при масках: /8, 11111111.11111111.00000000.00000000, 255.255.254.0 и /4 <br>
        `HOSTMIN HOSTMAX for network 12.167.38.4 with mask /8, /16 , /23` <br>
        ![alt text](screenshots/hosts_8_16_23.png) <br>
        `HOSTMIN HOSTMAX for network 12.167.38.4 with mask /4` <br>
        ![alt text](screenshots/hosts_4.png) <br>

 * 1.2. localhost <br>
    Определи и запиши в отчёт, можно ли обратиться к приложению, работающему на localhost, со следующими IP: 194.34.23.100, 127.0.0.2, 127.1.0.1, 128.0.0.1 <br>

    127.0.0.2, 127.1.0.1 c этими ip можно обратиться к приложению, так как они находятся в диапазоне ip адресов предназначенных для localhost <br>
    `Диапазон localhost` <br>
    ![alt text](screenshots/range_localhosts.png) <br>
    `Список localhost` <br>
    ![alt text](screenshots/localhosts.png) <br>

 * 1.3. Диапазоны и сегменты сетей <br>
    Определи и запиши в отчёт: <br>
     + 1) Какие из перечисленных IP можно использовать в качестве публичного, а какие только в качестве частных: 10.0.0.45, 134.43.0.2, 192.168.4.2, 172.20.250.4, 172.0.2.1, 192.172.0.1, 172.68.0.2, 172.16.255.255, 10.10.10.10, 192.169.168.1 <br>

     В качестве частных можно использовать следующие ip адреса: 10.0.0.45, 192.168.4.2, 172.20.250.4, 172.16.255.255, 10.10.10.10. <br>
      `Private networks`  <br>
     ![alt text](screenshots/172_16_0_0__12.png) <br>
     ![alt text](screenshots/10_0_0_0__8.png) <br>
     ![alt text](screenshots/192_168_0_0__16.png) <br>
      `10.0.0.45, 192.168.4.2, 172.20.250.4` <br>
      ![alt text](screenshots/private_networks_1.png) <br>
      `172.16.255.255, 10.10.10.10` <br>
      ![alt text](screenshots/private_networks_2.png) <br>

     В качестве публичных можно использовать остальные ip адреса: 134.43.0.2,  172.0.2.1, 192.172.0.1, 172.68.0.2,  192.169.168.1. <br>
     `134.43.0.2,  172.0.2.1, 192.172.0.1` <br>
     ![alt text](screenshots/public_networks_1.png) <br>
     `172.68.0.2,  192.169.168.1` <br>
     ![alt text](screenshots/public_networks_2.png) <br>

     + 2) Какие из перечисленных IP адресов шлюза возможны у сети 10.10.0.0/18: 10.0.0.1, 10.10.0.2, 10.10.10.10, 10.10.100.1, 10.10.1.255 <br>
        IP адресов шлюза возможных у сети 10.10.0.0/18: 10.10.0.2, 10.10.10.10. <br>
        `Диапазон ip в которых может находится шлюз` <br>
        ![alt text](screenshots/gateway.png) <br>


## Part 2. Статическая маршрутизация между двумя машинами <br>

 * Подними две виртуальные машины (далее -- ws1 и ws2). <br>

    + С помощью команды ip a посмотри существующие сетевые интерфейсы <br>
    ![alt text](screenshots/ip_a.png) <br>

    + Опиши сетевой интерфейс, соответствующий внутренней сети, на обеих машинах и задать следующие адреса и маски: ws1 - 192.168.100.10, маска /16, ws2 - 172.24.116.8, маска /12. <br>
    ![alt text](screenshots/ch_files_netplan.png) <br>

    + Выполни команду netplan apply для перезапуска сервиса сети. <br>
    ![alt text](screenshots/netplan_apply.png) <br>

 * 2.1. Добавление статического маршрута вручную <br>

    + Добавь статический маршрут от одной машины до другой и обратно при помощи команды вида ip r add. <br>

    + Пропингуй соединение между машинами. <br>
    ![alt text](screenshots/ping_virt_m.png) <br>

 * 2.2. Добавление статического маршрута с сохранением <br>
    + Добавь статический маршрут от одной машины до другой с помощью файла etc/netplan/00-installer-config.yaml. <br>
    ![alt text](screenshots/static_route.png) <br>

    + Пропингуй соединение между машинами. <br>
    ![alt text](screenshots/ping_static.png) <br>

## Part 3. Утилита iperf3 <br>

 * 3.1. Скорость соединения <br>
   + 8 Mbps = 1 mb/s <br>
   + 100 Mbps = 12.5 mb/s <br>
   + 1 Gbps = 125 mb/s <br>

 * 3.2. Утилита iperf3  <br>
   + Измерь скорость соединения между ws1 и ws2. <br>
   ![alt text](screenshots/iperf_1_2.png) <br>

   ![alt text](screenshots/iperf_2_1.png) <br>


## Part 4. Сетевой экран <br>
 * 4.1. Утилита iptables <br>
   `firewall.sh на ws1 и ws2` <br>
   ![alt text](screenshots/firewall.png) <br>

 * 4.2. Утилита nmap <br>
   `ping result` <br>
   ![alt text](screenshots/ping_firewall.png) <br>
   `nmap result` <br>
   ![alt text](screenshots/nmap.png) <br>

## Part 5. Статическая маршрутизация сети <br>
 * 5.1. Настройка адресов машин <br>
   + Настрой конфигурации машин в etc/netplan/00-installer-config.yaml согласно сети на рисунке. <br>
   `conf ws11, ws21, ws22` <br>
  ![alt text](screenshots/ws123_1.png) <br>
   `conf r1, r2` <br>
  ![alt text](screenshots/r12.png) <br>

   + Перезапусти сервис сети. Если ошибок нет, то командой ip -4 a проверь, что адрес машины задан верно. Также пропингуй ws22 с ws21. Аналогично пропингуй r1 с ws11. <br>
   `ip -4 a ws21, ws22, r2` <br>
  ![alt text](screenshots/ip4_a_ws23_r2.png) <br>
   `ip -4 a ws11, r1` <br>
  ![alt text](screenshots/ip4_a_ws1_r1.png) <br>

   `ping ws22 ws21` <br>
   ![alt text](screenshots/ping_ws22_ws21.png) <br>
   `ping r1 ws11` <br>
   ![alt text](screenshots/ping_r1_ws11.png) <br>
 
 * 5.2. Включение переадресации IP-адресов <br>
   + Для включения переадресации IP, выполни команду `sysctl -w net.ipv4.ip_forward=1` на роутерах: <br>
   ![alt text](screenshots/forward1.png) <br>
   + Открой файл /etc/sysctl.conf и добавь в него следующую строку `net.ipv4.ip_forward = 1`: <br>
   `net.ipv4.ip_forward = 1 r1` <br>
   ![alt text](screenshots/sysctl_conf_r1.png) <br>
   `net.ipv4.ip_forward = 1 r2` <br>
   ![alt text](screenshots/sysctl_conf_r2.png) <br>

 * 5.3. Установка маршрута по-умолчанию <br>
   + Настрой маршрут по-умолчанию (шлюз) для рабочих станций. Для этого добавь default перед IP роутера в файле конфигураций. <br>
   ![alt text](screenshots/default_ws21_ws22.png) <br>
   ![alt text](screenshots/default_ws11.png) <br>

   + Вызови ip r и покажи, что добавился маршрут в таблицу маршрутизации. <br>
   ![alt text](screenshots/ws23_ip_r.png) <br>
   ![alt text](screenshots/ws11_ip_r.png) <br>

   + Пропингуй с ws11 роутер r2 и покажи на r2, что пинг доходит. Для этого используй команду:  <br>
   `tcpdump -tn -i enp0s8` <br>
   ![alt text](screenshots/ws11_ping__r2.png) <br>

 * 5.4. Добавление статических маршрутов <br>
   + Добавь в роутеры r1 и r2 статические маршруты в файле конфигураций. Пример для r1 маршрута в сетку 10.20.0.0/26: <br>
   ![alt text](screenshots/netplan_conf_r1_r2.png) <br>

   + Вызови ip r и покажи таблицы с маршрутами на обоих роутерах. Пример таблицы на r1: <br>
   `ip r r1 , r2` <br>
   ![alt text](screenshots/ip_r_r1_r2.png) <br>

   + Запусти команды на ws11: <br>
    `ip r list 10.10.0.0/[маска сети] и ip r list 0.0.0.0/0` <br>
   ![alt text](screenshots/ip_r_list.png) <br>

     В отчёте объясни, почему для адреса 10.10.0.0/[маска сети] был выбран маршрут, отличный от 0.0.0.0/0, хотя он попадает под маршрут по-умолчанию. <br>

      Из за того что этот адрес `10.10.0.0/[маска сети]` имеет конкретику, то он более приоритетный при выборе маршрута. <br>

* 5.5. Построение списка маршрутизаторов <br>

   + Запусти на r1 команду дампа `tcpdump -tnv -i eth0`. <br>
   +  При помощи утилиты traceroute построй список маршрутизаторов на пути от ws11 до ws21. <br>
   ![alt text](screenshots/tracerout_ws21.png) <br>
   ![alt text](screenshots/tcpdump_r1.png) <br>
   Traceroute - это утилита, которая используется для определения маршрута данных от отправителя к получателю в сети TCP/IP. При помощи traceroute отправляются пакеты данных с увеличивающимся значением TTL (Time to Live) в заголовке IP. Когда пакет достигает узла на пути с сниженным TTL, данный узел отправляет сообщение ICMP "Time Exceeded" обратно отправителю. Таким образом, traceroute определяет каждый узел на маршруте до целевого узла.
   Из вывода, полученного из дампа на r1, можно увидеть последовательное изменение TTL в пакетах, направленных к целевому узлу. Как только TTL в пакете становится равным 0, узел на пути отправляет обратно сообщение об ошибке, и traceroute продолжает отправку пакетов с увеличенным TTL.
   Таким образом, принцип работы построения пути при помощи traceroute основан на переборе узлов на маршруте к целевому узлу путем поочередной отправки пакетов с изменяющимся значением TTL и анализа ответов от узлов на пути. <br>

 * 5.6. Использование протокола ICMP при маршрутизации <br>
   + Запусти на r1 перехват сетевого трафика, проходящего через eth0 с помощью команды `tcpdump -n -i eth0 icmp`. <br>
   + Пропингуй с ws11 несуществующий IP (например, 10.30.0.111) с помощью команды `ping -c 1 10.30.0.111`. <br>
   ![alt text](screenshots/ping_fail.png) <br>

## Part 6. Динамическая настройка IP с помощью DHCP <br>

 * Для r2 настрой в файле /etc/dhcp/dhcpd.conf конфигурацию службы DHCP: <br>
    1) Укажи адрес маршрутизатора по-умолчанию, DNS-сервер и адрес внутренней сети. <br>
  `/etc/dhcp/dhcpd.conf` <br>
  ![alt text](screenshots/dhcp_conf.png) <br>
  2) В файле resolv.conf пропиши nameserver 8.8.8.8. <br>
  `/etc/resolve.conf` <br>
  ![alt text](screenshots/resolve_conf.png) <br>

 * Перезагрузи службу DHCP командой systemctl restart isc-dhcp-server. Машину ws21 перезагрузи при помощи reboot и через ip a покажи, что она получила адрес. Также пропингуй ws22 с ws21. <br> 
  `systemctl restart isc-dhcp-server` <br>
  ![alt text](screenshots/restart_dhcp.png) <br>
  ![alt text](screenshots/6_2.png) <br>

  Укажи MAC адрес у ws11, для этого в etc/netplan/00-installer-config.yaml надо добавить строки: macaddress: 10:10:10:10:10:BA, dhcp4: true. <br>
  ![alt text](screenshots/6_3.png) <br>

  Для r1 настрой аналогично r2, но сделай выдачу адресов с жесткой привязкой к MAC-адресу (ws11). Проведи аналогичные тесты. <br>

  `dhcp.conf r1` <br>
  ![alt text](screenshots/6_4.png) <br>
 
  `resolv.conf r1` <br>
  ![alt text](screenshots/6_5.png) <br>

  `systemctl restart isc-dhcp-server r1` <br>
  ![alt text](screenshots/6_6.png) <br>

  `ip a ws11` <br>
  ![alt text](screenshots/6_7.png) <br>


  ` ip a до` <br>
  ![alt text](screenshots/6_8.png) <br>

  `sudo dhclient -r явно освобождает текущую аренду, и как только аренда будет освобождена, клиент завершает работу.` <br>

  `sudo dhclient Теперь получите новый IP-адрес с помощью DHCP в Linux` <br>

  ` ip a после` <br>
  ![alt text](screenshots/6_9.png) <br>

  ## Part 7. NAT
 * В файле /etc/apache2/ports.conf на ws22 и r1 измени строку Listen 80 на Listen 0.0.0.0:80, то есть сделай сервер Apache2 общедоступным.<br>
  ![alt text](screenshots/7_1.png)<br>

 * Запусти веб-сервер Apache командой service apache2 start на ws22 и r1.<br>
  ![alt text](screenshots/7_2.png)<br>

 * Добавь в фаервол, созданный по аналогии с фаерволом из Части 4, на r2 следующие правила:<br>
1) Удаление правил в таблице filter - iptables -F;<br>
2) Удаление правил в таблице "NAT" - iptables -F -t nat;<br>
3) Отбрасывать все маршрутизируемые пакеты - iptables --policy FORWARD DROP.<br>
![alt text](screenshots/7_2_1.png)<br>
 Запусти файл также, как в Части 4.<br>
![alt text](screenshots/7_3.png)<br>
Проверь соединение между ws22 и r1 командой ping.<br>
![alt text](screenshots/7_4.png)<br>


 * Добавь в файл ещё одно правило:<br>
4) Разрешить маршрутизацию всех пакетов протокола ICMP.<br>
  Запусти файл также, как в Части 4.<br>
  Проверь соединение между ws22 и r1 командой ping.<br>
  ![alt text](screenshots/7_6.png)<br>

* Добавь в файл ещё два правила:<br>

5) Включи SNAT, а именно маскирование всех локальных ip из локальной сети, находящейся за r2 (по обозначениям из Части 5 - сеть 10.20.0.0).<br>
6) Включи DNAT на 8080 порт машины r2 и добавить к веб-серверу Apache, запущенному на ws22, доступ извне сети.<br>

![alt text](screenshots/7_7.png)<br>
  Проверь соединение по TCP для SNAT: для этого с ws22 подключиться к серверу Apache на r1 командой:
  `telnet [адрес] [порт]`<br>
  ![alt text](screenshots/7_8.png)<br>

  Проверь соединение по TCP для DNAT: для этого с r1 подключиться к серверу Apache на ws22 командой telnet (обращаться по адресу r2 и порту 8080).<br>
  ![alt text](screenshots/7_9.png)<br>


  ## Part 8. Дополнительно. Знакомство с SSH Tunnels<br>

  * Запусти на r2 фаервол с правилами из Части 7.<br>
  ![alt text](screenshots/8_2.png)<br>
  ![alt text](screenshots/8_3.png)<br>
  * Запусти веб-сервер Apache на ws22 только на localhost (то есть в файле /etc/apache2/ports.conf измени строку Listen 80 на Listen localhost:80).<br>
  ![alt text](screenshots/8_1.png)<br>

 * Воспользуйся Local TCP forwarding с ws21 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws21.<br>
  `ssh -L 9999:localhost:80 ivan@10.20.0.20`<br>
  ![alt text](screenshots/8_4.png)<br>
  `telnet localhost 9999 и netstat с портом 9999`<br>
  ![alt text](screenshots/8_5.png)<br>

  * Воспользуйся Remote TCP forwarding c ws11 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws11.<br>
  `ssh -R 9999:localhost:80 ivan@10.20.0.10`<br>
  ![alt text](screenshots/8_6.png)<br>
  `telnet localhost 9999 и netstat с портом 9999`<br>
  ![alt text](screenshots/8_7.png)<br>