#ifndef COMMANDSYSTEMMAP_H
#define COMMANDSYSTEMMAP_H

#include "CommandSystem.h"


// 不在映射表的程序，用完整路径可直接启动，用文件名则需依赖环境变量。
// 手动添加时，注意斜杠，win默认反斜杠，要改成正斜杠
// 2. 应用名称到命令的映射
// 将map设为全局，而非设置
const QMap<QString, QStringList> CommandSystem::appMap = []{
    QMap<QString, QStringList> map;
    // map.insert("notepad", {"D:/Notepad++/notepad.exe"});
    map.insert("notepad", {"D:/Notepad++/notepad++.exe"});      // 这种方式可以在新窗口中打开程序
    // map.insert("thonny", {"D:/Thonny/thonny.exe"});      // 直接在输入框键入完整路径的方式速度更快，非常快

    map.insert("Steam", {"C:/Users/Public/Desktop/Steam.exe"});     // 快捷方式无法执行
    map.insert("ak", {"D:/AKPlatform/AK.exe"});
    map.insert("微信开发者工具", {"D:/微信web开发者工具/微信开发者工具.exe"});
    map.insert("uv4", {"D:/Keil_v5/UV4/UV4.exe"});



    map.insert("acrobat", {"D:/AcrobatDC2024/Acrobat/Acrobat.exe"});
    map.insert("acrodist", {"D:/AcrobatDC2024/Acrobat/acrodist.exe"});
    map.insert("activate_matlab", {"G:/matlab2016/bin/win64/activate_matlab.exe"});
    map.insert("adobemediaencoder", {"D:/ME/Adobe Media Encoder 2021/Adobe Media Encoder.exe"});
    map.insert("adobepremierepro", {"D:/PR/Adobe Premiere Pro 2021/Adobe Premiere Pro.exe"});
    map.insert("AD", {"D:/AltiumDesigner24/X2.EXE"});
    map.insert("advanced_ip_scanner", {"C:/Program Files (x86)/Advanced IP Scanner/advanced_ip_scanner.exe"});
    map.insert("android studio", {"D:/Androidstudio/bin/studio64.exe"});
    // map.insert("ME", {"D:/M/Adobe Media Encoder 2021/Adobe Media Encoder.exe"});
    map.insert("ak", {"D:/AKPlatform/AK.exe"});
    map.insert("appcertui", {"C:/Program Files (x86)/Windows Kits/10/App Certification Kit/appcertui.exe"});
    map.insert("appverif", {"C:/Windows/SysWOW64/appverif.exe", "C:/Windows/System32/appverif.exe"});
    map.insert("arduino", {"D:/Arduino/arduino.exe"});
    map.insert("assistant", {"D:/QTcreator/6.9.1/mingw_64/bin/assistant.exe"});
    map.insert("autostart", {"D:/Chinatelecom_GDPortal/AutoStart.exe"});
    map.insert("baidunetdisk", {"D:/BaiduNetdisk/BaiduNetdisk.exe"});
    map.insert("bandizip", {"C:/Program Files/Bandizip/Bandizip.exe"});
    map.insert("battle.net", {"D:/Battle.net/Battle.net.exe"});
    map.insert("battle.netlauncher", {"D:/Battle.net/Battle.net Launcher.exe"});
    map.insert("canva", {"C:/Users/phoen/AppData/Local/Programs/Canva/Canva.exe"});
    map.insert("charmap", {"C:/WINDOWS/system32/charmap.exe"});
    map.insert("chrome", {"C:/Program Files/Google/Chrome/Application/chrome.exe"});
    map.insert("clashforwindows", {"C:/Users/phoen/Downloads/Clash.for.Windows-0.20.38-win/Clash for Windows.exe"});
    map.insert("cleanmgr", {"C:/WINDOWS/system32/cleanmgr.exe"});
    map.insert("cmake-gui", {"E:/CMAKE/bin/cmake-gui.exe"});
    map.insert("cmd", {"C:/WINDOWS/system32/cmd.exe", "C:/Windows/System32/cmd.exe"});
    map.insert("code", {"C:/Users/phoen/AppData/Local/Programs/Microsoft VS Code/Code.exe"});
    map.insert("coh2语言切换工具", {"H:/SteamLibrary/steamapps/common/Company of Heroes 2/COH2语言切换工具.exe"});
    map.insert("control", {"C:/WINDOWS/system32/control.exe"});
    map.insert("cursor", {"C:/Users/phoen/AppData/Local/Programs/cursor/Cursor.exe"});
    map.insert("deactivate_matlab", {"G:/Program Files/MATLAB/R2022a/uninstall/bin/win64/deactivate_matlab.exe", "G:/matlab2016/uninstall/bin/win64/deactivate_matlab.exe"});
    map.insert("designer", {"D:/QTcreator/6.9.1/mingw_64/bin/designer.exe"});
    map.insert("devenv", {"D:/VSStudioComm2022/Common7/IDE/devenv.exe"});
    map.insert("dfrgui", {"C:/WINDOWS/system32/dfrgui.exe"});
    map.insert("dingtalklauncher", {"D:/钉钉/DingDing/DingtalkLauncher.exe"});
    map.insert("doubao", {"C:/Users/phoen/AppData/Local/Doubao/Doubao.exe"});
    map.insert("doxywizard", {"D:/doxygen/bin/doxywizard.exe"});
    map.insert("dqsinstaller", {"G:/SQL数据/MSSQL14.MSSQLSERVER/MSSQL/Binn/DQSInstaller.exe"});
    map.insert("dtswizard", {"C:/Program Files/Microsoft SQL Server/150/DTS/Binn/DTSWizard.exe"});
    map.insert("espc", {"D:/EasyShare/espc.exe"});
    map.insert("evelauncher", {"E:/EVE/Launcher/evelauncher.exe"});
    map.insert("explorer", {"C:/WINDOWS/explorer.exe"});
    map.insert("filezilla", {"D:/FileZilla FTP Client/FileZilla.exe", "D:/FileZilla FTP Client/filezilla.exe"});
    map.insert("firefox", {"C:/Program Files/Mozilla Firefox/firefox.exe"});
    map.insert("furmark", {"C:/Program Files (x86)/Geeks3D/Benchmarks/FurMark/FurMark.exe"});
    map.insert("fusionlauncher", {"C:/Users/phoen/AppData/Local/Autodesk/webdeploy/production/6a0c9611291d45bb9226980209917c3d/FusionLauncher.exe"});
    map.insert("git-bash", {"D:/Git/git-bash.exe"});
    map.insert("git-cmd", {"D:/Git/git-cmd.exe"});
    map.insert("git-gui", {"D:/Git/cmd/git-gui.exe"});
    map.insert("gpuview", {"C:/Program Files (x86)/Windows Kits/10/Windows Performance Toolkit/gpuview/GPUView.exe"});
    map.insert("iscsicpl", {"C:/WINDOWS/system32/iscsicpl.exe"});
    map.insert("koodoreader", {"D:/KooDoReader/Koodo Reader/Koodo Reader.exe"});
    map.insert("ksolaunch", {"D:/WPS Office/ksolaunch.exe"});
    map.insert("ksomisc", {"D:/WPS Office/12.1.0.21915/office6/ksomisc.exe"});
    map.insert("landingpage", {"C:/Program Files/Microsoft SQL Server/150/Setup Bootstrap/SQL2019/x64/LandingPage.exe"});
    map.insert("lceda-pro", {"D:/lceda-pro/lceda-pro.exe"});
    map.insert("lghub", {"C:/Program Files/LGHUB/lghub.exe"});
    map.insert("lghub_system_tray", {"C:/Program Files/LGHUB/system_tray/lghub_system_tray.exe"});
    map.insert("linguist", {"D:/QTcreator/6.9.1/mingw_64/bin/linguist.exe"});
    map.insert("livecaptions", {"C:/WINDOWS/system32/LiveCaptions.exe"});
    map.insert("magicavoxel", {"E:/迅雷下载/MagicaVoxel-0.99.7.1-win64/MagicaVoxel-0.99.7.1-win64/MagicaVoxel.exe"});
    map.insert("magnify", {"C:/WINDOWS/system32/magnify.exe"});
    map.insert("maintenancetool", {"D:/QTcreator/MaintenanceTool.exe", "E:/EVE/maintenancetool.exe"});
    map.insert("matlab", {"G:/matlab2016/bin/matlab.exe"});
    map.insert("mdsched", {"C:/WINDOWS/system32/MdSched.exe"});
    map.insert("mmc", {"C:/WINDOWS/System32/mmc.exe", "C:/Windows/SysWOW64/mmc.exe"});
    map.insert("mobarte", {"D:/MobaXterm/MobaXterm/MobaRTE.exe"});
    map.insert("mobaxterm", {"D:/MobaXterm/MobaXterm/MobaXterm.exe"});
    map.insert("mockitt", {"C:/Users/phoen/AppData/Local/mockingbot-studio/Mockitt.exe"});
    map.insert("modorganizer", {"D:/MODManager/ModOrganizer.exe"});
    map.insert("morphvoxpro", {"D:/morph/MorphVOXPro.exe"});
    map.insert("msconfig", {"C:/WINDOWS/system32/msconfig.exe"});
    map.insert("msedge", {"C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe"});
    map.insert("msiexec", {"C:/Windows/SysWOW64/msiexec.exe"});
    map.insert("msinfo32", {"C:/WINDOWS/system32/msinfo32.exe"});
    map.insert("mstsc", {"C:/WINDOWS/system32/mstsc.exe"});
    map.insert("narrator", {"C:/WINDOWS/system32/narrator.exe"});
    map.insert("newshortcut1_69c2b9a012c943f8b6bc658d1ac73474", {"C:/WINDOWS/Installer/{A61131DC-B92D-4AD8-A925-E2D6D5FE217C}/NewShortcut1_69C2B9A012C943F8B6BC658D1AC73474.exe"});
    map.insert("newshortcut2_87edf6c81d0a4b7b84f42fe0c6a9d608", {"C:/WINDOWS/Installer/{F24FAABB-0C72-4F06-9B55-DB08C884730C}/NewShortcut2_87EDF6C81D0A4B7B84F42FE0C6A9D608.exe"});
    map.insert("node", {"C:/Program Files/nodejs/node.exe"});
    map.insert("notepad++", {"D:/Notepad++/notepad++.exe"});
    map.insert("notepad++安装助手", {"C:/Users/phoen/AppData/Local/Programs/notepad/Notepad++安装助手.exe"});
    map.insert("notion", {"C:/Users/phoen/AppData/Local/Programs/Notion/Notion.exe"});
    map.insert("notioncalendar", {"C:/Users/phoen/AppData/Local/Programs/cron-web/Notion Calendar.exe"});
    map.insert("obs64", {"D:/obs-studio/bin/64bit/obs64.exe"});
    map.insert("obsidian", {"D:/Obsidian/Obsidian.exe"});
    map.insert("odbcad32", {"C:/WINDOWS/system32/odbcad32.exe", "C:/WINDOWS/syswow64/odbcad32.exe"});
    map.insert("ollamaapp", {"C:/Users/phoen/AppData/Local/Programs/Ollama/ollama app.exe"});
    map.insert("onedrive", {"C:/Users/phoen/AppData/Local/Microsoft/OneDrive/OneDrive.exe"});
    map.insert("osk", {"C:/WINDOWS/system32/osk.exe"});
    map.insert("perfmon", {"C:/WINDOWS/system32/perfmon.exe"});
    map.insert("photoshop", {"D:/PS/Adobe Photoshop 2021/Photoshop.exe"});
    map.insert("picpick", {"D:/PicPick/picpick.exe", "E:/迅雷下载/picpick_portable/picpick.exe"});
    map.insert("polyspace-bug-finder", {"G:/matlab2016/polyspace/bin/polyspace-bug-finder.exe"});
    map.insert("polyspace-code-prover", {"G:/matlab2016/polyspace/bin/polyspace-code-prover.exe"});
    map.insert("powershell", {"C:/Windows/SysWOW64/WindowsPowerShell/v1.0/powershell.exe", "C:/Windows/System32/WindowsPowerShell/v1.0/powershell.exe"});
    map.insert("powershell_ise", {"C:/WINDOWS/system32/WindowsPowerShell/v1.0/PowerShell_ISE.exe", "C:/WINDOWS/syswow64/WindowsPowerShell/v1.0/PowerShell_ISE.exe"});
    map.insert("private_browsing", {"C:/Program Files/Mozilla Firefox/private_browsing.exe"});
    map.insert("psr", {"C:/WINDOWS/system32/psr.exe"});
    map.insert("python", {"C:/Python312/python.exe", "C:/Python313/python.exe"});
    map.insert("pythonw", {"C:/Python312/pythonw.exe", "C:/Python313/pythonw.exe"});
    map.insert("qqlive", {"D:/QQLive/QQLive.exe"});
    map.insert("qqliveuninstaller", {"D:/QQLive/QQLiveUninstaller.exe"});
    map.insert("qqmusic", {"D:/QQMusic/QQMusic.exe"});
    map.insert("qtcreator", {"D:/QTcreator/Tools/QtCreator/bin/qtcreator.exe"});
    map.insert("qtdesignstudio", {"D:/QTcreator/Tools/QtDesignStudio/bin/qtdesignstudio.exe"});
    map.insert("recoverydrive", {"C:/WINDOWS/system32/RecoveryDrive.exe"});
    map.insert("regedit", {"C:/WINDOWS/regedit.exe"});
    map.insert("rpi-imager", {"D:/Raspberry Pi Imager/rpi-imager.exe"});
    map.insert("run_fontforge", {"D:/FontForgeBuilds/run_fontforge.exe"});
    map.insert("securecrt", {"E:/ub2004sf/Yueqian/6818工具/SecureCRT/SecureCRT.exe"});
    map.insert("setup", {"C:/Program Files (x86)/Microsoft Visual Studio/Installer/setup.exe"});
    map.insert("sldbgdwld", {"C:/Program Files (x86)/Common Files/SOLIDWORKS 安装管理程序/BackgroundDownloading/sldBgDwld.exe"});
    map.insert("sldim", {"C:/WINDOWS/SolidWorks/IM_20230-40001-1100-100/sldim/sldIM.exe"});
    map.insert("sqlwtsn", {"C:/Program Files/Microsoft SQL Server/150/Shared/SqlWtsn.exe"});
    map.insert("squareline_studio", {"D:/SquareLine Studio 1.4.2/SquareLine_Studio.exe"});
    map.insert("steam", {"D:/steam/Steam.exe", "D:/steam/steam.exe"});
    map.insert("studio64", {"D:/Androidstudio/bin/studio64.exe"});
    map.insert("taskmgr", {"C:/WINDOWS/system32/taskmgr.exe"});
    map.insert("tftpd32", {"E:/ub2004sf/Yueqian/6818工具/Tftpd32/Tftpd32.exe"});
    map.insert("thonny", {"D:/Thonny/thonny.exe"});
    map.insert("thunder", {"D:/Thunder/Program/Thunder.exe"});
    map.insert("thunderstart", {"D:/Thunder/Program/ThunderStart.exe"});
    map.insert("thunderuninstall", {"D:/Thunder/Program/ThunderUninstall.exe"});
    map.insert("toggltrack", {"C:/Users/phoen/AppData/Local/TogglTrack/TogglTrack.exe"});
    map.insert("typeeasy", {"D:/Typeeasy/11.5/TypeEasy.exe", "D:/Typeeasy/TypeEasy.exe"});
    map.insert("typora", {"C:/Users/phoen/Documents/xwechat_files/wxid_pjsc42nib5l922_99ea/msg/file/2025-06/Typora/Typora/Typora.exe"});
    map.insert("unins000", {"C:/Program Files (x86)/Geeks3D/Benchmarks/FurMark/unins000.exe", "C:/Program Files/OpenSSL-Win64/unins000.exe", "C:/Users/phoen/AppData/Local/Programs/Ollama/unins000.exe", "D:/FontForgeBuilds/unins000.exe", "D:/MODManager/unins000.exe", "D:/doxygen/system/unins000.exe", "D:/lceda-pro/unins000.exe"});
    map.insert("uninst", {"D:/BaiduNetdisk/uninst.exe", "D:/Chinatelecom_GDPortal/uninst.exe", "D:/Dict/uninst.exe", "D:/EasyShare/uninst.exe", "D:/Typeeasy/11.5/uninst.exe", "D:/钉钉/DingDing/uninst.exe"});
    map.insert("uninstall", {"C:/Program Files/Npcap/uninstall.exe", "D:/AKPlatform/Uninstall.exe", "D:/FileZilla FTP Client/uninstall.exe", "D:/SquareLine Studio 1.4.2/Uninstall.exe", "D:/WXWork/Uninstall.exe", "D:/Weixin/Uninstall.exe", "D:/obs-studio/uninstall.exe", "D:/steam/uninstall.exe"});
    map.insert("unity", {"E:/Unity/Unity editor/2020.3.40f1c1/Editor/Unity.exe"});
    map.insert("unitybugreporter", {"E:/Unity/Unity editor/2020.3.40f1c1/Editor/BugReporter/UnityBugReporter.exe"});
    map.insert("uu_launcher", {"D:/Netease/UU/uu_launcher.exe"});
    map.insert("uv4", {"D:/Keil_v5/UV4/UV4.exe"});
    map.insert("vmcreate", {"C:/Program Files/Hyper-V/VMCreate.exe"});
    map.insert("vmnetcfg", {"D:/VMwareWorkstationPro/vmnetcfg.exe"});
    map.insert("vmplayer", {"D:/VMwareWorkstationPro/vmplayer.exe"});
    map.insert("vmware", {"D:/VMwareWorkstationPro/vmware.exe"});
    map.insert("voiceaccess", {"C:/WINDOWS/system32/voiceaccess.exe"});
    map.insert("weixin", {"D:/Weixin/Weixin.exe"});
    map.insert("wemeetapp", {"C:/Program Files/Tencent/WeMeet/wemeetapp.exe"});
    map.insert("wemeetuninstall", {"C:/Program Files/Tencent/WeMeet/3.35.1.435/WeMeetUninstall.exe"});
    map.insert("wfs", {"C:/WINDOWS/system32/WFS.exe"});
    map.insert("wintoast", {"D:/Git/mingw64/bin/wintoast.exe"});
    map.insert("wireshark", {"D:/Wireshark/Wireshark.exe"});
    map.insert("wmplayer", {"C:/Program Files (x86)/Windows Media Player/wmplayer.exe"});
    map.insert("wpa", {"C:/Program Files (x86)/Windows Kits/10/Windows Performance Toolkit/wpa.exe"});
    map.insert("wprui", {"C:/Program Files (x86)/Windows Kits/10/Windows Performance Toolkit/WPRUI.exe"});
    map.insert("wslg", {"C:/Program Files/WSL/wslg.exe"});
    map.insert("wxwork", {"D:/WXWork/WXWork.exe"});
    map.insert("x2", {"D:/AltiumDesigner24/X2.EXE", "D:/AltiumDesigner24/X2.exe"});
    map.insert("xmind", {"C:/Users/phoen/AppData/Local/Programs/Xmind/Xmind.exe"});
    map.insert("youdaodict", {"D:/Dict/YoudaoDict.exe"});
    map.insert("z-library", {"D:/Zlibrary/Z-Library/Z-Library.exe"});
    map.insert("z-tool2.0", {"C:/Texas Instruments/ZStack-CC2530-2.3.0-1.4.0/Tools/Z-Tool/Z-Tool 2.0.exe"});
    map.insert("zoad", {"C:/Texas Instruments/ZStack-CC2530-2.3.0-1.4.0/Tools/ZOAD/ZOAD.exe"});
    map.insert("卸载微信开发者工具", {"D:/微信web开发者工具/卸载微信开发者工具.exe"});
    map.insert("微信开发者工具", {"D:/微信web开发者工具/微信开发者工具.exe"});
    map.insert("有道云笔记", {"D:/youdaonote/ynote-desktop/有道云笔记.exe"});



    // 跨平台命令定义
#ifdef Q_OS_WIN
    map.insert("计算器", {"cmd.exe", "/c", "start", "calc.exe"});
    map.insert("记事本", {"cmd.exe", "/c", "start", "notepad.exe"});
    map.insert("终端", {"cmd.exe"});
#elif defined(Q_OS_MACOS)
    map.insert("计算器", {"open", "-a", "Calculator"});
    map.insert("记事本", {"open", "-a", "TextEdit"});
    map.insert("终端", {"open", "-a", "Terminal"});
#else
    map.insert("计算器", {"gnome-calculator"});ne
        map.insert("记事本", {"gedit"});
    map.insert("终端", {"gnome-terminal"});
#endif
    return map;
}();









#endif // COMMANDSYSTEMMAP_H
