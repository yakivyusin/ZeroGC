Fork of [kkokosa/UpsilonGC](https://github.com/kkokosa/UpsilonGC) with updated Zero GCs to launch on .NET Core 3.1.1.

## Custom GCs in .NET

Starting from .NET Core 2.0 coupling between Garbage Collector and the Execution Engine itself have been loosened. Prior to this version, the Garbage Collector code was pretty much tangled with the rest of the CoreCLR code. However, Local GC initiative in version 2.1 is already mature enough to start using it. The purpose of the exercise we are going to do is to prepare Zero Garbage Collector that replaces the default one. And then move to implement something more sophisticated.

## Zero Garbage Collector

Zero Garbage Collector is the simplest possible implementation that in fact does almost nothing. It only allows you to allocate objects, because this is obviously required by the Execution Engine. Created objects are never automatically deleted and theoretically, no longer needed memory is never reclaimed. Why one would be interested in such a simple GC implementation? There are at least two reasons:
* it is an excellent basis for the development of your own Garbage Collection mechanism. It provides the necessary functionality to make runtime work properly and you can build on top of that.
* it may be interesting for special use cases like very short living applications or such that almost no allocate memory (you can come up with those concepts as No-alloc or Zero-alloc programming). In such case providing GC overhead is unnecessary and it may be wise to get rid of it. It is like making huge GC.TryStartNoGCRegion over all you application.

More motivation you may find in JVM's recently added [Epsilon GC](https://openjdk.java.net/jeps/318) which is exactly the same concept, as its proposal explains:

> "Develop a GC that handles memory allocation but does not implement any actual memory reclamation mechanism. Once the available Java heap is exhausted, the JVM will shut down."

## Samples

It is super important to set the GC to workstation mode, instead of Server mode. As explained in articles below, even in custom GC the difference between Workstation and Server should be irreleveant, this setting influece how runtime handles write barriers. In case of Server GC it will end in StackOverflowException or any other nasty crash.

## Materials

You can find detailed description of the project:
* [Zero Garbage Collector for .NET Core](http://tooslowexception.com/zero-garbage-collector-for-net-core)
* [Zero Garbage Collector for .NET Core 2.1 and ASP.NET Core 2.1](http://tooslowexception.com/zero-garbage-collector-for-net-core-2-1-and-asp-net-core-2-1/)
* [My 'Make your custom .NET GC - "whys" and "hows"' given at DotNext Moscow 2018](https://www.youtube.com/watch?v=om8YFyTO5ik)
