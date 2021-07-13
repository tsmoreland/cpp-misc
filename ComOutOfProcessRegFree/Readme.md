## Registration Free Not Supported

Project was originally intended as a proof of concept or simple example of registration free out of process but that goal has since 
been abandonded.  Instead this project now serves as a simple use of a out of process COM server

## Official Support for Registration Free (or lack there of)

[Simplify App Deployment with ClickOnce and Registration-Free COM](https://docs.microsoft.com/en-us/archive/msdn-magazine/2005/april/simplify-app-deployment-with-clickonce-and-registration-free-com#S4)

Of course, the biggest limitation of Reg-Free COM is that it only works on the Windows XP operating system or higher. It also requires changes to the way in which components are loaded in the core operating system. Unfortunately, there is no down-level support layer for Reg-Free COM.

Not every component is a suitable candidate for use under Reg-Free COM. A component is not considered suitable if any of the following are true:

- The component is an out-of-process (ActiveX EXE) server. Only DLLs are supported.
- The component is a system component or part of the operating system, such as XML, Data Access, Internet Explorer, or DirectX® components. For example, you should not attempt to isolate components such as Microsoft XML (MSXml.dll) or Microsoft Internet Controls (SHDocVw.dll). These components are either part of the operating system, or can be installed with a separate redistributable package.
- The component is part of an application, such as Microsoft Office. For example, you should not attempt to isolate components such as the Microsoft Word Object Model or Microsoft Excel Object Model. These two components are part of Office and can only be used on a machine that has the full Office product installed on it.
- The component is intended for use as an add-in or a snap-in, such as an Office add-in or a control in a Web browser. Such components typically require some kind of registration scheme defined by the hosting environment that is beyond the scope of the manifest itself. The other problem is an arbitrary application may not be designed to recognize isolated components, as it probably doesn't have a way to reference your component through a manifest.
- The component manages a shared physical or virtual system resource. For example, it could manage some kind of data connection shared between multiple applications or a device driver for a print spooler.