//
// Copyright © 2022 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

using System;
using System.Runtime.InteropServices;

namespace TSMoreland.Interop.InProcessComServer.NetFramework;

[ComVisible(true)]
[Guid("B3863C61-327A-461C-BB9C-5B8B36D3BAF5")]
public sealed class SimpleNetFrameworkObject : ISimpleNetFrameworkObject
{
    /// <inheritdoc />
    public string Name { get; set; } = nameof(SimpleNetFrameworkObject);

    /// <inheritdoc />
    public int Value { get; set; } = 42;

    /// <inheritdoc />
    public double CalculateAreaOfACircle(double radius)
    {
        return 2 * Math.PI * radius * radius;
    }
}
