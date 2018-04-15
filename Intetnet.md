1.重置winsock：netsh winsock reset

2.重置Tcp/ip协议：netsh int ip reset C://resetlog.txt 存储日志文件

3.通过设备管理器更新或者卸载驱动

4.卸载重装VPN

5.ipconfig/flushdns 清除dns
       /?               显示此帮助消息
       /all             显示完整配置信息。
       /release         释放指定适配器的 IPv4 地址。
       /release6        释放指定适配器的 IPv6 地址。
       /renew           更新指定适配器的 IPv4 地址。
       /renew6          更新指定适配器的 IPv6 地址。
       /flushdns        清除 DNS 解析程序缓存。
       /registerdns     刷新所有 DHCP 租用并重新注册 DNS 名称
       /displaydns      显示 DNS 解析程序缓存的内容。
       /showclassid     显示适配器允许的所有 DHCP 类 ID。
       /setclassid      修改 DHCP 类 ID。
       /showclassid6    显示适配器允许的所有 IPv6 DHCP 类 ID。
       /setclassid6     修改 IPv6 DHCP 类 ID。
-----------------------------------------------------------------

6.硬件问题，路由出错

7.netstat -r  查看路由表
  netstat/?  查看所有操作的帮助


