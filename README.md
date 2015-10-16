<h1>(Sp)atial (I)ntegrated (D)evelopment (E)nvironment</h1>

This is a C application intended to improve workflow
by mapping different aspects of development to spatial 
representations, like the 'mind maps' used to improve
memory.

Everything is configured for Linux, but CSFML is
available for Linux and Windows, and this source 
should be platform-independent. By version 0.1, cross-
compiled versions should be tested and available. 

<h3>Usage</h3>
<table><tr>
	<th>Build (verbose)</th>
	<td><code>make</code></td>
</tr><tr>
	<th>Build (quiet)</th>
	<td><code>make -s</code></td>
</tr><tr>
	<th>Build (silent)</th>
	<td><code>make &gt;/dev/null</code></td>
</tr><tr>
	<th>Build and run</th>
	<td><code>make do</code></td>
</tr><tr>
	<th ROWSPAN=3>Run (prebuilt)</th>
	<td><code>$(BINDIR)build</code></td>
</tr><tr>
	<td><s>$(BINDIR)build32.exe</s> (todo)</td>
</tr><tr>
	<td><s>$(BINDIR)build64.exe</s> (todo)</td>
</tr></table>

<h3>Structure</h3>

<table>
<tr>
	<th>$(INCIDR)</th>
	<th>$(SRCDIR)</th>
	<th>$(OBJDIR)</th>
	<th>$(BINDIR)</th>
	<th>Description</th>
</tr><tr>
	<td>util.h</td>
	<td COLSPAN=2></td>
	<td ROWSPAN=6></td>
	<td>Utilities and macros</td>
</tr><tr>
	<td>log.h</td>
	<td>log.c</td>
	<td>log.o</td>
	<td>Logging to stdout or an external file.</td>
</tr><tr>
	<td>streams.h</td>
	<td>streams.c</td>
	<td>streams.o</td>
	<td>Printing and stream operators</td>
</tr><tr>
	<td>net.h</td>
	<td>net.c</td>
	<td>net.o</td>
	<td>Network tools (todo)</td>
</tr><tr>
	<td>view.h</td>
	<td>view.c</td>
	<td>view.o</td>
	<td>Graphics module - rendering and UI</td>
</tr><tr>
	<td>main.h</td>
	<td>main.c</td>
	<td>main.o</td>
	<td>Application entry point</td>
</tr><tr>
	<td COLSPAN=3 ROWSPAN=3></td>
	<td>spide</td>
	<td>Linux executable</td>
</tr><tr>
	<td><s>spide32.exe</s></td>
	<td>32-bit Windows executable (todo)</td>
</tr><tr>
	<td><s>spide64.exe</s></td>
	<td>64-bit Windows executable (todo)</td>
</tr></table>


