window.BENCHMARK_DATA = {
  "lastUpdate": 1765912871794,
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
          "id": "70e239b75581251136cc623bf0066b188caf18d2",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-15T18:28:54+01:00",
          "tree_id": "5042959cf9bf18b2f1b6d5e363204c1003ee88ef",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/70e239b75581251136cc623bf0066b188caf18d2"
        },
        "date": 1765819887514,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 357.962,
            "range": "± 8.99078",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 624.596,
            "range": "± 8.55258",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 1.64857,
            "range": "± 37.2296",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1.35137,
            "range": "± 45.0825",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 116.03,
            "range": "± 13.5828",
            "unit": "ns",
            "extra": "100 samples\n353 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.167,
            "range": "± 3.17941",
            "unit": "ns",
            "extra": "100 samples\n431 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.6531,
            "range": "± 1.60674",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.5983,
            "range": "± 557.55",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 128.05,
            "range": "± 6.17784",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 81.9714,
            "range": "± 3.98821",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 975.12,
            "range": "± 25.8168",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 974.765,
            "range": "± 34.6184",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 151.648,
            "range": "± 4.45645",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 383.041,
            "range": "± 6.10103",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 43.0556,
            "range": "± 5.33838",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 44.2699,
            "range": "± 4.64591",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 53.9169,
            "range": "± 2.69704",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.5997,
            "range": "± 2.54035",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 357.338,
            "range": "± 8.77186",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 361.293,
            "range": "± 11.5724",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.17,
            "range": "± 4.57222",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 343.623,
            "range": "± 6.18756",
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
          "id": "dba44d1255c900fe2444fdac2e28ce6d2efb1a32",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-16T20:16:46+01:00",
          "tree_id": "dc2eb5fd7fb44c9c0aab0bcdf9eee4d2a8db44a4",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/dba44d1255c900fe2444fdac2e28ce6d2efb1a32"
        },
        "date": 1765912870938,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 355.143,
            "range": "± 9.80523",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 624.072,
            "range": "± 7.03478",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 1.66896,
            "range": "± 32.5528",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1.35543,
            "range": "± 44.5212",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 112.883,
            "range": "± 4.31589",
            "unit": "ns",
            "extra": "100 samples\n349 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.836,
            "range": "± 4.54987",
            "unit": "ns",
            "extra": "100 samples\n425 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.6156,
            "range": "± 1.48844",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.5787,
            "range": "± 539.151",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 127.028,
            "range": "± 3.87021",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 85.4086,
            "range": "± 4.93884",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 981.174,
            "range": "± 27.0113",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 977.011,
            "range": "± 26.6206",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 152.181,
            "range": "± 6.4322",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 383.012,
            "range": "± 7.19593",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 39.6656,
            "range": "± 6.49741",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 41.3526,
            "range": "± 7.44712",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 52.8543,
            "range": "± 2.42661",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.5231,
            "range": "± 2.10786",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 360.511,
            "range": "± 8.33541",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 362.133,
            "range": "± 8.25104",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 376.155,
            "range": "± 11.4858",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 343.287,
            "range": "± 4.57011",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}