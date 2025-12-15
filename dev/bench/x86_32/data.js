window.BENCHMARK_DATA = {
  "lastUpdate": 1765819133186,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark (x86_32)": [
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "5900b5935264621bb7b7b332e48f842a5da935c9",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-14T21:20:19+01:00",
          "tree_id": "d09077e0ded4cc83602fec81e0a6c0aa43887319",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/5900b5935264621bb7b7b332e48f842a5da935c9"
        },
        "date": 1765743782659,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 357.379,
            "range": "± 11.937",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 628.333,
            "range": "± 21.1154",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 2.35905,
            "range": "± 47.1413",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 2.05061,
            "range": "± 48.2031",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 112.999,
            "range": "± 3.77539",
            "unit": "ns",
            "extra": "100 samples\n361 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.3012,
            "range": "± 2.97474",
            "unit": "ns",
            "extra": "100 samples\n445 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 47.0898,
            "range": "± 2.90095",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.6506,
            "range": "± 640.4",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 125.479,
            "range": "± 4.33936",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 81.6475,
            "range": "± 4.2618",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 963.624,
            "range": "± 22.1533",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 973.158,
            "range": "± 36.7745",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 153.176,
            "range": "± 5.09182",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 382.955,
            "range": "± 6.07176",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 42.6388,
            "range": "± 5.53812",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 44.0085,
            "range": "± 5.72405",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 54.0742,
            "range": "± 2.57637",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 63.4237,
            "range": "± 6.40369",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 368.97,
            "range": "± 7.82833",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 368.947,
            "range": "± 7.65994",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.986,
            "range": "± 5.13812",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 344.019,
            "range": "± 4.43326",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "19398ac0a93230173d84cce5b5a44a11ecc8dc9c",
          "message": "Simplify github benchmark workflow",
          "timestamp": "2025-12-15T18:16:19+01:00",
          "tree_id": "bdf118407dc61dfced5175e0d6247d8c7dfcd760",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/19398ac0a93230173d84cce5b5a44a11ecc8dc9c"
        },
        "date": 1765819132291,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 369.286,
            "range": "± 7.89187",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 628.107,
            "range": "± 21.8048",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 1.65046,
            "range": "± 27.4708",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1.35241,
            "range": "± 30.59",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 115.488,
            "range": "± 26.0429",
            "unit": "ns",
            "extra": "100 samples\n349 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.1501,
            "range": "± 3.17447",
            "unit": "ns",
            "extra": "100 samples\n428 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.7629,
            "range": "± 1.71742",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.6771,
            "range": "± 812.074",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 127.585,
            "range": "± 4.28185",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 85.9702,
            "range": "± 4.53207",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 995.025,
            "range": "± 31.343",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 1003.3399999999999,
            "range": "± 31379.4",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 151.646,
            "range": "± 5.21847",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 383.586,
            "range": "± 5.53677",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 45.5215,
            "range": "± 3.69631",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 46.4603,
            "range": "± 3.69497",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 54.1077,
            "range": "± 2.46183",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.6362,
            "range": "± 3.25527",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 357.821,
            "range": "± 9.1106",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 363.515,
            "range": "± 8.05371",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 375.117,
            "range": "± 6.30859",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 343.998,
            "range": "± 4.62331",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}