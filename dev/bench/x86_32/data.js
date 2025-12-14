window.BENCHMARK_DATA = {
  "lastUpdate": 1765743783485,
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
      }
    ]
  }
}