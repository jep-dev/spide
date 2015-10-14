# (Sp)atial (I)ntegrated (D)evelopment (E)nvironment

This is a C application intended to improve workflow
by mapping different aspects of development to spatial 
representations, like the 'mind maps' used to improve
memory.

Everything is configured for Linux, but CSFML is
available for Linux and Windows, and this source 
should be platform-independent. By version 0.1, cross-
compiled versions should be tested and available. 

### Building 
<table><tr>
<td>verbose</td>
<td><code>make</code></td>
</tr><tr>
<td>quiet</td>
<td><code>make -s</code></td>
</tr><tr>
<td>silent</td>
<td><code>make &gt;/dev/null</code></td>
</tr></table>

### Usage
<code>./build/spide</code>

### Structure
<table>
<tr>
	<th>./include/</th>
	<th>./source/</th>
	<th>./build/</th>
	<th>Description</th>
</tr><tr>
	<td>util.h</td>
	<td></td>
	<td></td>
	<td>Utilities and macros</td>
</tr><tr>
	<td>streams.h</td>
	<td>streams.c</td>
	<td></td>
	<td>Printing and stream operators</td>
</tr><tr>
	<td>log.h</td>
	<td>log.c</td>
	<td></td>
	<td>Logging to stdout or an external file.</td>
</tr><tr>
	<td>net.h</td>
	<td>net.c</td>
	<td></td>
	<td>Network tools (todo)</td>
</tr><tr>
	<td>view.h</td>
	<td>view.c</td>
	<td></td>
	<td>Graphics module - rendering and UI</td>
</tr><tr>
	<td>main.h</td>
	<td>main.c</td>
	<td></td>
	<td>Application entry point</td>
</tr><tr>
	<td></td>
	<td></td>
	<td>linux.py</td>
	<td>Network tools (todo)</td>
</tr>
</table>


